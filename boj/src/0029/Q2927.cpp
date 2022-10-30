// BOJ 2927 [Exploring Antarctica]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 30001
#define SEGMAX 65536
#define QMAX 300001

int seg[SEGMAX];
bool visited[MAX];
vector<int> bd[MAX]; // bi-directional
vector<int> ud[MAX]; // uni-directional

// sum segment tree
void seg_update(int i, int v) {
    i |= SEGMAX >> 1;
    seg[i] = v;
    while (i >>= 1) seg[i] = seg[i<<1] + seg[i<<1|1];
}
int seg_query(int l, int r) {
    l |= SEGMAX >> 1, r |= SEGMAX >> 1;
    int ret = 0;
    while (l <= r) {
        if (l & 1) ret += seg[l++];
        if (~r & 1) ret += seg[r--];
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
        ret += seg_query(in[top[v]], in[v]);
        v = par[top[v]];
    }
    if(dep[v] > dep[u]) swap(v, u);
    ret += seg_query(in[v], in[u]);
    return ret;
}

// union-find
int uf[MAX];
int uf_find(int v){
    if(uf[v] < 0) return v;
    return uf[v] = uf_find(uf[v]);
}
void uf_uni(int a, int b){
    a = uf_find(a), b = uf_find(b);
    uf[a] = b;
}

int N, Q, peng[MAX];
bool qpos[QMAX];
vector<pair<int, pair<int,int>>> queries;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=1; i<=N; ++i) cin >> peng[i];

    cin >> Q;
    memset(uf, -1, sizeof(uf));
    memset(qpos, true, sizeof(qpos));
    for(int i=0; i<Q; ++i){
        string s; int x, y;
        cin >> s >> x >> y;
        if(s[0] == 'b'){ // bridge
            if(uf_find(x) == uf_find(y)) qpos[i] = false;
            else {
                bd[x].push_back(y);
                bd[y].push_back(x);
                uf_uni(x, y);
            }
            queries.push_back({0, {x, y}});
        }
        else if(s[0] == 'e'){ // excursion
            if(uf_find(x) != uf_find(y)) qpos[i] = false;
            queries.push_back({1, {x, y}});
        }
        else{ // penguins
            queries.push_back({2, {x, y}});
        }
    }

    // convert graph to tree
    for(int i=1; i<=N; ++i) if(!visited[i]) dfs_convert(i);

    // decompose
    for(int i=1; i<=N; ++i) if(!in[i]) {
        dep[i] = 1, par[i] = i, top[i] = i;
        dfs_subtree(i), dfs_decompose(i);
    }

    // update
    for(int i=1; i<=N; ++i) hld_update(i, peng[i]);

    // process queries
    for(int i=0; i<Q; ++i){
        int q = queries[i].first, x = queries[i].second.first, y = queries[i].second.second;
        if(q == 0) cout << (qpos[i] ? "yes" : "no") << '\n';
        else if(q == 1) cout << (qpos[i] ? to_string(hld_query(x, y)) : "impossible") << '\n';
        else hld_update(x, y);
    }
}
