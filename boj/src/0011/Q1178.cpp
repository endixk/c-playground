// BOJ 1178 [Adding Edges]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

// Tarjan's algorithm
vector<int> graph[MAX], id(MAX);
vector<vector<int>> SCC;
bool visited[MAX];
stack<int> S;
int cnt = 0;
int dfs(int cur){
    visited[cur] = true;
    int ret = id[cur] = ++cnt;
    S.push(cur);
    for(int nxt : graph[cur]){
        if(!id[nxt]) ret = min(ret, dfs(nxt));
        else if(visited[nxt]) ret = min(ret, id[nxt]);
    }
    if(ret == id[cur]){
        vector<int> scc;
        while(true){
            int t = S.top(); S.pop();
            scc.push_back(t);
            visited[t] = false;
            id[t] = MAX;
            if(t == cur) break;
        }
        SCC.push_back(scc);
    }
    return ret;
}

vector<int> odds;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int V, E; cin >> V >> E;
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // get connected components
    for(int i=1; i<=V; i++) if(!id[i]) dfs(i);
    for(const auto& scc : SCC){
        int odd = 0;
        for(int v : scc) if(graph[v].size() % 2) odd++;
        odds.push_back(odd);
    }

    int ans = 0, odd = odds[0];
    for(int i=1; i<SCC.size(); i++){
        ans++;
        odd = (odd ? odd-1 : 1) + (odds[i] ? odds[i]-1 : 1);
    }
    if(odd == 0) cout << ans;
    else cout << ans + (odd - 2) / 2;
}
