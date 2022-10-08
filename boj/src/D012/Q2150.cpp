// BOJ 2150 [Strongly Connected Component]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Kosaraju's algorithm
vector<int> graph[MAX], rev_graph[MAX];
bool visited[MAX];
stack<int> S;
void dfs_init(int v){
    visited[v] = true;
    for(int next : graph[v]){
        if(!visited[next]) dfs_init(next);
    }
    S.push(v);
}

vector<vector<int>> SCC;
void dfs_scc(int v){
    visited[v] = true;
    SCC.back().push_back(v);
    for(int next : rev_graph[v]){
        if(!visited[next]) dfs_scc(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int V, E; cin >> V >> E;
    for(int i = 0; i < E; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    for(int i = 0; i < V; i++) if(!visited[i]) dfs_init(i);
    memset(visited, false, sizeof(visited));
    while(!S.empty()){
        int v = S.top(); S.pop();
        if(!visited[v]){
            SCC.emplace_back();
            dfs_scc(v);
        }
    }

    for(auto &scc : SCC) sort(scc.begin(), scc.end());
    sort(SCC.begin(), SCC.end());
    SCC.erase(SCC.begin());

    cout << SCC.size() << '\n';
    for(auto &scc : SCC) {
        for (int v: scc) cout << v << ' ';
        cout << -1 << '\n';
    }
}
