// BOJ 1761 [Distance between Vertices]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int depth[40001], parent[40001][20], dist[40001][20];
vector<pair<int, int>> graph[40001];

// generate LCA tables
void generate(int cur, int par, int d){
    depth[cur] = d;
    parent[cur][0] = par;
    for (int i = 1; i < 20; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
        dist[cur][i] = dist[cur][i - 1] + dist[parent[cur][i - 1]][i - 1];
    }
    for (auto [next, w] : graph[cur]) {
        if (next == par) continue;
        dist[next][0] = w;
        generate(next, cur, d + 1);
    }
}

// run LCA algorithm to calculate distance
int lca(int u, int v){
    int ret = 0;
    if (depth[u] < depth[v]) swap(u, v);

    // move u to same depth with v
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - depth[v] >= (1 << i)) {
            ret += dist[u][i];
            u = parent[u][i];
        }
    }
    if (u == v) return ret;

    // move u and v to same parent
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            ret += dist[u][i] + dist[v][i];
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    // return distance
    return ret + dist[u][0] + dist[v][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v, d; cin >> u >> v >> d;
        graph[u].emplace_back(v, d);
        graph[v].emplace_back(u, d);
    }

    generate(1, 0, 1);
    int M; cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}
