// BOJ 11266 [Articulation Point]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

vector<int> graph[MAX];
int reach[MAX], iter;
bool art[MAX];

int dfs(int v, bool root){
    reach[v] = ++iter;
    int ret = reach[v];
    int child = 0;
    for (int u : graph[v]) {
        if (reach[u]) { // visited
            ret = min(ret, reach[u]);
            continue;
        }
        // not visited
        child++;
        int low = dfs(u, false);
        if (!root && low >= reach[v]) art[v] = true;
        ret = min(ret, low);
    }
    if (root && child >= 2) art[v] = true;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int V, E; cin >> V >> E;
    while(E--){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=V; ++i) if(!reach[i]) dfs(i, true);

    vector<int> ans;
    for(int i=1; i<=V; ++i) if(art[i]) ans.push_back(i);
    cout << ans.size() << '\n';
    for(int v : ans) cout << v << ' ';
}
