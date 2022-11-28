// BOJ 17429 [International Messi Organization]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
#define MAX 500001
#define SEG 1048576

// lazy prop segtree
uint seg[SEG], mlazy[SEG], plazy[SEG];
void propagate(int node, int s, int e){
    if(mlazy[node] != 1){
        seg[node] *= mlazy[node];
        if(s != e){
            mlazy[node*2] *= mlazy[node];
            mlazy[node*2+1] *= mlazy[node];
            plazy[node*2] *= mlazy[node];
            plazy[node*2+1] *= mlazy[node];
        }
        mlazy[node] = 1;
    }
    if(plazy[node] != 0){
        seg[node] += plazy[node] * (e-s+1);
        if(s != e){
            plazy[node*2] += plazy[node];
            plazy[node*2+1] += plazy[node];
        }
        plazy[node] = 0;
    }
}

void seg_update(int node, int s, int e, int l, int r, uint m, uint p){
    propagate(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){
        mlazy[node] *= m;
        plazy[node] += p;
        propagate(node, s, e);
        return;
    }
    int mid = (s+e)/2;
    seg_update(node*2, s, mid, l, r, m, p);
    seg_update(node*2+1, mid+1, e, l, r, m, p);
    seg[node] = seg[node*2] + seg[node*2+1];
}

uint seg_query(int node, int s, int e, int l, int r){
    propagate(node, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return seg[node];
    int mid = (s+e)/2;
    return seg_query(node*2, s, mid, l, r) + seg_query(node*2+1, mid+1, e, l, r);
}

// heavy-light decomposition
vector<int> bd[MAX], ud[MAX];
bool visited[MAX];
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

int N, Q;
void subtree_update(int v, uint m, uint p){
    seg_update(1, 1, N, in[v], out[v], m, p);
}
uint subtree_query(int v){
    return seg_query(1, 1, N, in[v], out[v]);
}
void path_update(int u, int v, uint m, uint p){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        seg_update(1, 1, N, in[top[u]], in[u], m, p);
        u = par[top[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    seg_update(1, 1, N, in[u], in[v], m, p);
}
uint path_query(int u, int v, uint m, uint p){
    uint ret = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        ret += seg_query(1, 1, N, in[top[u]], in[u]);
        u = par[top[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    ret += seg_query(1, 1, N, in[u], in[v]);
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> Q;
    for(int i=1; i<N; ++i){
        int u, v; cin >> u >> v;
        bd[u].push_back(v), bd[v].push_back(u);
    }

    dfs_convert(1);
    dfs_subtree(1);
    dfs_decompose(1);

    while(Q--){
        int t, x, y, v; cin >> t;
        switch(t){
            case 1:
                cin >> x >> v;
                subtree_update(x, 1, v);
                break;
            case 2:
                cin >> x >> y >> v;
                path_update(x, y, 1, v);
                break;
            case 3:
                cin >> x >> v;
                subtree_update(x, v, 0);
                break;
            case 4:
                cin >> x >> y >> v;
                path_update(x, y, v, 0);
                break;
            case 5:
                cin >> x;
                cout << subtree_query(x) << '\n';
                break;
            case 6:
                cin >> x >> y;
                cout << path_query(x, y, 1, 0) << '\n';
                break;
        }
    }
}
