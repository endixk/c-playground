// BOJ 18227 [Water Tanks]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 200001

ll seg[1<<19], lazy[1<<19];

void propagate(int node, int s, int e){
    if(lazy[node]){
        seg[node] += (e-s+1)*lazy[node];
        if(s != e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int s, int e, int l, int r, int v){
    propagate(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){
        seg[node] += (e-s+1)*v;
        if(s != e){
            lazy[node*2] += v;
            lazy[node*2+1] += v;
        }
        return;
    }
    int m = (s+e)/2;
    update(node*2, s, m, l, r, v);
    update(node*2+1, m+1, e, l, r, v);
    seg[node] = seg[node*2] + seg[node*2+1];
}

ll query(int node, int s, int e, int l, int r){
    propagate(node, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return seg[node];
    int m = (s+e)/2;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

vector<int> adj[MAX];
bool visited[MAX];
int trv[MAX], child[MAX], depth[MAX], cnt;
void dfs(int v, int d){
    if(visited[v]) return;
    visited[v] = true;
    trv[v] = ++cnt;
    depth[v] = d;
    for(int u : adj[v]) dfs(u, d+1);
    child[trv[v]] = cnt - trv[v];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, C; cin >> N >> C;
    for(int i=1; i<N; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(C, 1);

    int M; cin >> M;
    for(int i=0; i<M; i++){
        int t, v; cin >> t >> v;
        if(t == 1) update(1, 1, N, trv[v], trv[v], 1);
        else cout << query(1, 1, N, trv[v], trv[v] + child[trv[v]]) * depth[v] << '\n';
    }
}
