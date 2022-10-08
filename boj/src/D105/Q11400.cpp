// BOJ 11400 [Articulation Bridge]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

vector<int> graph[MAX];
int reach[MAX], iter;
vector<pair<int,int>> arts;

int dfs(int curr, int prev){
    reach[curr] = ++iter;
    int ret = reach[curr];
    for(int next : graph[curr]){
        if(next == prev) continue;
        if(reach[next] == 0){
            int low = dfs(next, curr);
            if(low > reach[curr]) arts.emplace_back(min(curr, next), max(curr, next));
            ret = min(ret, low);
        } else ret = min(ret, reach[next]);
    }
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

    sort(arts.begin(), arts.end());
    cout << arts.size() << '\n';
    for(auto [u, v] : arts) cout << u << ' ' << v << '\n';
}
