// BOJ 5820 [Race]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
#define MAXN 200005
#define MAXK 1000005

vector<pair<int,int>> adj[MAXN];
int N, K, sz[MAXN], depth[MAXK];
bool visited[MAXN];

// centroid decomposition
int get_sz(int u, int p) {
    sz[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (v == p || visited[v]) continue;
        sz[u] += get_sz(v, u);
    }
    return sz[u];
}
int get_cent(int u, int p, int n) {
    for (auto [v, w] : adj[u]) {
        if (v == p || visited[v]) continue;
        if (sz[v] > n / 2) return get_cent(v, u, n);
    }
    return u;
}

// preprocess min depth array
queue<int> Q;
void min_depth(int u, int p, int dis, int dep){
    if(dis > K) return;
    depth[dis] = min(depth[dis], dep);
    Q.emplace(dis);
    for (auto [v, w] : adj[u]) {
        if (v == p || visited[v]) continue;
        min_depth(v, u, dis + w, dep + 1);
    }
}
int get_cost(int u, int p, int dis, int dep){
    int ret = INF;
    if(dis > K) return ret;
    if(depth[K - dis] < INF) ret = min(ret, depth[K - dis] + dep);
    for (auto [v, w] : adj[u]) {
        if (v == p || visited[v]) continue;
        ret = min(ret, get_cost(v, u, dis + w, dep + 1));
    }
    return ret;
}
int solve(int u){
    // init
    int ret = INF;
    while(!Q.empty()) depth[Q.front()] = INF, Q.pop();

    // get centroid
    int n = get_sz(u, -1);
    int c = get_cent(u, -1, n);
    visited[c] = true;

    // find cost
    depth[0] = 0;
    for (auto [v, w] : adj[c]) {
        if (visited[v]) continue;
        ret = min(ret, get_cost(v, c, w, 1));
        min_depth(v, c, w, 1);
    }

    // decompose
    for (auto [v, w] : adj[c]) {
        if (visited[v]) continue;
        ret = min(ret, solve(v));
    }

    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    for(int i=0; i<N-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for(int i=0; i<=K; ++i) depth[i] = INF;

    int ans = solve(1);
    if(ans == INF) cout << -1;
    else cout << ans;
}
