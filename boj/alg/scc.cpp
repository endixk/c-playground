// Strongly connected component finding algorithms
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

vector<vector<int>> SCC;
vector<int> graph[MAX];
vector<int> rev_graph[MAX]; // Kosaraju
vector<int> id(MAX); // Tarjan
bool visited[MAX];
stack<int> S;

// Tarjan's algorithm
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

// Kosaraju's algorithm
void dfs_init(int v){
    visited[v] = true;
    for(int next : graph[v]){
        if(!visited[next]) dfs_init(next);
    }
    S.push(v);
}
void dfs_scc(int v){
    visited[v] = true;
    SCC.back().push_back(v);
    for(int next : rev_graph[v]){
        if(!visited[next]) dfs_scc(next);
    }
}
void kosajaru(int V){
    for(int i = 0; i < V; i++) if(!visited[i]) dfs_init(i);
    memset(visited, false, sizeof(visited));
    while(!S.empty()){
        int v = S.top(); S.pop();
        if(!visited[v]){
            SCC.emplace_back();
            dfs_scc(v);
        }
    }
}
