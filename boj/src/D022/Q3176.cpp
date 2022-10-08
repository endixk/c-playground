// BOJ 3176 [Road Network]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int depth[MAX], parent[MAX][20], dmax[MAX][20], dmin[MAX][20];
vector<pair<int, int>> graph[MAX];

// generate LCA tables
void generate(int cur, int par, int d){
    depth[cur] = d;
    parent[cur][0] = par;
    for (int i = 1; i < 20; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
        dmax[cur][i] = max(dmax[cur][i - 1], dmax[parent[cur][i - 1]][i - 1]);
        dmin[cur][i] = min(dmin[cur][i - 1], dmin[parent[cur][i - 1]][i - 1]);
    }
    for (auto [next, w] : graph[cur]) {
        if (next == par) continue;
        dmax[next][0] = dmin[next][0] = w;
        generate(next, cur, d + 1);
    }
}

// run LCA algorithm to calculate max/min distance
pair<int,int> lca(int u, int v){
    pair<int,int> ret = {0, 1e9};
    if (depth[u] < depth[v]) swap(u, v);

    // move u to same depth with v
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - depth[v] >= (1 << i)) {
            ret.first = max(ret.first, dmax[u][i]);
            ret.second = min(ret.second, dmin[u][i]);
            u = parent[u][i];
        }
    }
    if (u == v) return ret;

    // move u and v to same parent
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            ret.first = max(ret.first, max(dmax[u][i], dmax[v][i]));
            ret.second = min(ret.second, min(dmin[u][i], dmin[v][i]));
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    // return distance
    ret.first = max(ret.first, max(dmax[u][0], dmax[v][0]));
    ret.second = min(ret.second, min(dmin[u][0], dmin[v][0]));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    generate(1, 0, 1);

    int K; cin >> K;
    while (K--) {
        int u, v;
        cin >> u >> v;
        auto [mx, mn] = lca(u, v);
        cout << mn << ' ' << mx << '\n';
    }
}
