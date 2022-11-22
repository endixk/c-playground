// BOJ 16074 [Mountaineers]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define EDGE pair<int,pair<int,int>>
#define MAX 255555
#define SEGMAX 524288

int seg[SEGMAX];
bool visited[MAX];
vector<int> bd[MAX]; // bi-directional
vector<int> ud[MAX]; // uni-directional

// max segment tree
void seg_update(int i, int v) {
    i |= SEGMAX >> 1;
    seg[i] = v;
    while (i >>= 1) seg[i] = max(seg[i<<1], seg[i<<1|1]);
}
int seg_query(int l, int r) {
    l |= SEGMAX >> 1, r |= SEGMAX >> 1;
    int ret = 0;
    while (l <= r) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (~r & 1) ret = max(ret, seg[r--]);
        l >>= 1, r >>= 1;
    }
    return ret;
}

// heavy-light decomposition
int par[MAX], dep[MAX], sz[MAX], top[MAX], in[MAX], out[MAX];

// DFS 1: convert graph to tree
void dfs_convert(int v){
    visited[v] = true;
    for(int u : bd[v]){
        if(visited[u]) continue;
        ud[v].push_back(u);
        dfs_convert(u);
    }
}

// DFS 2: analyze and fix subtree
void dfs_subtree(int v){
    sz[v] = 1;
    for(int &u : ud[v]){
        dep[u] = dep[v] + 1, par[u] = v;
        dfs_subtree(u);
        sz[v] += sz[u];
        if(sz[u] > sz[ud[v][0]]) swap(u, ud[v][0]);
    }
}

// DFS 3: decompose tree
int it;
void dfs_decompose(int v){
    in[v] = ++it;
    for(int u : ud[v]){
        top[u] = (u == ud[v][0] ? top[v] : u);
        dfs_decompose(u);
    }
    out[v] = it;
}

// HLD update
void hld_update(int v, int c){
    seg_update(in[v], c);
}

// HLD query
int hld_query(int v, int u){
    int ret = 0;
    while(top[v] != top[u]){
        if(dep[top[v]] < dep[top[u]]) swap(v, u);
        ret = max(ret, seg_query(in[top[v]], in[v]));
        v = par[top[v]];
    }
    if(dep[v] > dep[u]) swap(v, u);
    ret = max(ret, seg_query(in[v], in[u]));
    return ret;
}

// Union-Find
int p[MAX];
int uf_find(int x){
    if(p[x] == x) return x;
    return p[x] = uf_find(p[x]);
}
void uf_union(int x, int y){
    x = uf_find(x);
    y = uf_find(y);
    p[y] = x;
}

// Kruskal's algorithm
vector<EDGE> edges;
vector<EDGE> mst;
void kruskal(){
    for(const EDGE& e : edges){
        if(uf_find(e.second.first) == uf_find(e.second.second)) continue;
        mst.push_back(e);
        uf_union(e.second.first, e.second.second);
    }
}

int val[MAX];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M, Q; cin >> N >> M >> Q;
    for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin >> val[i*M+j+1];
    for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
        int v = i*M + j + 1;
        for(int k=0; k<4; ++k){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            int u = nx*M + ny + 1;
            edges.push_back({max(val[v], val[u]), {v, u}});
            edges.push_back({max(val[v], val[u]), {u, v}});
        }
    }
    sort(edges.begin(), edges.end());
    for(int i=1; i<=N*M; ++i) p[i] = i;
    kruskal();

    // HLD
    for(EDGE e : mst){
        int v = e.second.first, u = e.second.second;
        bd[v].push_back(u);
        bd[u].push_back(v);
    }
    par[1] = 1;
    dfs_convert(1);
    dfs_subtree(1);
    dfs_decompose(1);
    for(int i=1; i<=N*M; ++i) hld_update(i, val[i]);

    // HLD query
    while(Q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int v = (--x1)*M + (--y1) + 1, u = (--x2)*M + (--y2) + 1;
        if(v == u) cout << val[v] << '\n';
        else cout << hld_query(v, u) << '\n';
    }
}
