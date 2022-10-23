// BOJ 16404 [Seungbeom Inc.]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int seg[1<<18], lazy[1<<18];

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

int query(int node, int s, int e, int l, int r){
    propagate(node, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return seg[node];
    int m = (s+e)/2;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

vector<int> adj[MAX];
int trv[MAX], child[MAX], cnt;
void dfs(int v){
    trv[v] = ++cnt;
    for(int u : adj[v]) dfs(u);
    child[trv[v]] = cnt - trv[v];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        int p; cin >> p;
        if(p>0) adj[p].push_back(i);
    }

    dfs(1);
    for(int i=0; i<M; i++){
        int t; cin >> t;
        if(t == 1){
            int v, w; cin >> v >> w;
            update(1, 1, N, trv[v], trv[v]+child[trv[v]], w);
        }
        else{
            int v; cin >> v;
            cout << query(1, 1, N, trv[v], trv[v]) << '\n';
        }
    }
}
