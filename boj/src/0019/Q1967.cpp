// BOJ 1967 [Diameter of Tree]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

vector<pair<int,int>> adj[MAX];
bool visited[MAX];
int mx = 0;

int dfs(int v){
    visited[v] = true;

    vector<int> dist;
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

    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int d = dfs(1);
    cout << max(d, mx);
}