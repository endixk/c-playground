// BOJ 1167 [Diameter of Tree]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

vector<pair<int,int>> adj[MAX];
bool visited[MAX];
ll mx = 0;

ll dfs(int v){
    visited[v] = true;

    vector<ll> dist;
    for(auto p : adj[v]){
        if(visited[p.first]) continue;
        dist.push_back(dfs(p.first) + p.second);
    }

    if(dist.empty()) return 0;
    if(dist.size() == 1) return dist[0];
    sort(dist.begin(), dist.end(), greater<>());
    mx = max(mx, dist[0] + dist[1]);
    return dist[0];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int V; cin >> V;
    for(int i = 0; i < V; i++){
        int v; cin >> v;
        while(true){
            int u, w; cin >> u;
            if(u == -1) break;
            cin >> w;
            adj[v].emplace_back(u, w);
        }
    }

    ll d = dfs(1);
    cout << max(d, mx);
}
