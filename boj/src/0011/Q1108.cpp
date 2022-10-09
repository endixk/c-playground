// BOJ 1108 [Search Engine]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#define WEB 2500
using namespace std;

map<string,int> M; int m = 0;

vector<int> graph[WEB], rev_graph[WEB], clean[WEB];
bool visited[WEB];
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
    cin.tie(nullptr);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        if(M.find(s) == M.end()) M[s] = m++;
        int v = M[s];

        int k; cin >> k;
        for(int j=0; j<k; j++){
            string t; cin >> t;
            if(M.find(t) == M.end()) M[t] = m++;
            int u = M[t];
            graph[u].push_back(v);
            rev_graph[v].push_back(u);
        }
    }
    string s; cin >> s;
    int V = M[s];

    // First DFS
    fill(visited, visited+WEB, false);
    for(int i=0; i<m; i++) if(!visited[i]) dfs_init(i);

    // Second DFS
    fill(visited, visited+WEB, false);
    while(!S.empty()){
        int v = S.top(); S.pop();
        if(!visited[v]){
            SCC.emplace_back();
            dfs_scc(v);
        }
    }

    // SCC Cleaning
    for(auto & scc : SCC){
        map<int,bool> member;
        for(int v : scc) member[v] = true;
        for(int v : scc)
            for(int next : graph[v])
                if(member.find(next) == member.end())
                    clean[v].push_back(next);
    }

    // topological sort
    long long indegree[m], score[m];
    fill(indegree, indegree+m, 0);
    fill(score, score+m, 1);
    for(int i=0; i<m; i++)
        for(int next : clean[i])
            indegree[next]++;
    queue<int> Q;
    for(int i=0; i<m; i++) if(indegree[i] == 0) Q.push(i);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(int next : clean[v]){
            score[next] += score[v];
            if(--indegree[next] == 0) Q.push(next);
        }
    }

    cout << score[V];
}
