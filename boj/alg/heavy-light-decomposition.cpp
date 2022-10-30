// Heavy-light decomposition
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define SEGMAX 262144

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