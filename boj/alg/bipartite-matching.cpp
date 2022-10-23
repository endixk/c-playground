// Bipartite matching with DFS
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<int> graph[MAX];
int match[MAX];
bool visited[MAX];

// bipartite matching
bool dfs(int u){
    for(int v: graph[u]){
        if(visited[v]) continue;
        visited[v] = true;
        if(match[v] == 0 || dfs(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}
