// BOJ 17399 [Circumcenter of a Tree]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int depth[MAX], parent[MAX][20];
vector<int> graph[MAX];

// generate LCA tables
void generate(int cur, int par, int d){
    depth[cur] = d;
    parent[cur][0] = par;
    for (int i = 1; i < 20; i++) parent[cur][i] = parent[parent[cur][i - 1]][i - 1];

    for (auto nxt : graph[cur]) {
        if (nxt == par) continue;
        generate(nxt, cur, d + 1);
    }
}

// find LCA
int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);

    // move u to same depth with v
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - depth[v] >= (1 << i)) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;

    // move u and v to same parent
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    // return LCA
    return parent[u][0];
}

int dist(int u, int v){
    int l = lca(u, v);
    if(l == u) return depth[v] - depth[u];
    if(l == v) return depth[u] - depth[v];
    return depth[u] + depth[v] - 2 * depth[l];
}

int par(int v, int d){
    for(int i = 0; i < 20; i++){
        if(d & (1 << i)) {
            v = parent[v][i];
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    generate(1, 0, 1);

    int Q; cin >> Q;
    while (Q--) {
        int a, b, c; cin >> a >> b >> c;

        int d;
        // (a, b)
        d = dist(a, b);
        if(d % 2 == 0){
            int mid = par(depth[a] > depth[b] ? a : b, d/2);
            if(dist(mid, c) == d/2){
                cout << mid << '\n';
                continue;
            }
        }
        // (a, c)
        d = dist(a, c);
        if(d % 2 == 0){
            int mid = par(depth[a] > depth[c] ? a : c, d/2);
            if(dist(mid, b) == d/2){
                cout << mid << '\n';
                continue;
            }
        }
        // (b, c)
        d = dist(b, c);
        if(d % 2 == 0){
            int mid = par(depth[b] > depth[c] ? b : c, d/2);
            if(dist(mid, a) == d/2){
                cout << mid << '\n';
                continue;
            }
        }
        cout << -1 << '\n';
    }
}
