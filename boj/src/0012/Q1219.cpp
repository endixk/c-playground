// BOJ 1219 [Mr. Oh's Concern]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 51
#define INF 0x3f3f3f3f3f3f3f3f

int N, M, S, E, val[MAX];
vector<pair<int, int>> adj[MAX];

// SPFA
ll dst[MAX], cnt[MAX];
queue<int> q; bool vis[MAX], inq[MAX], cyc[MAX];

bool bfs(int s, int e){
    memset(vis, 0, sizeof(vis));
    q.push(s), vis[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto [v, w] : adj[u]){
            if(!vis[v]) q.push(v), vis[v] = true;
        }
    }
    return vis[e];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> S >> E >> M;
    for(int i=0; i<M; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    for(int i=0; i<N; ++i) cin >> val[i];
    if(!bfs(S, E)) return cout << "gg", 0;

    // SPFA
    fill(dst, dst+N, INF);
    dst[S] = -val[S];
    q.push(S); inq[S] = true;
    while(!q.empty()){
        int u = q.front(); q.pop(); inq[u] = false;
        for(auto [v, w] : adj[u]){
            if(dst[v] > dst[u] + w - val[v]){
                dst[v] = dst[u] + w - val[v];
                if(!inq[v] && !cyc[v]){
                    if(++cnt[v] >= N) cyc[v] = true;
                    if(!cyc[v]) q.push(v), inq[v] = true;
                }
            }
        }
    }
    for(int i=0; i<N; ++i) if(cyc[i] && bfs(i, E)) return cout << "Gee", 0;
    cout << -dst[E];
}
