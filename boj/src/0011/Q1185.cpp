// BOJ 1185 [Cheering Up the Cows]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
#define EDGE pair<int,pair<int,int>>

// Union-Find
int p[MAX];
int uf_find(int x){
    if(p[x] == x) return x;
    return p[x] = uf_find(p[x]);
}
void uf_union(int x, int y){
    x = uf_find(x);
    y = uf_find(y);
    p[y] = x;
}

// Kruskal's algorithm
int V, E;
vector<EDGE> edges;
vector<EDGE> mst;
void kruskal(){
    for(const EDGE& e : edges){
        if(uf_find(e.second.first) == uf_find(e.second.second)) continue;
        mst.push_back(e);
        uf_union(e.second.first, e.second.second);
    }
}

vector<int> cost(MAX);
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> V >> E;

    int cmin = MAX;
    for(int i=1; i<=V; i++) {
        cin >> cost[i];
        cmin = min(cmin, cost[i]);
        p[i] = i;
    }
    for(int i=0; i<E; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({2*w + cost[u] + cost[v], {u, v}});
    }

    sort(edges.begin(), edges.end());
    kruskal();

    int ans = 0;
    for(auto& e : mst) ans += e.first;
    cout << ans + cmin;
}
