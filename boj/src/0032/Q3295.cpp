// BOJ 3295 [One-way Link Network]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<int> graph[MAX];
int match[MAX];
void reset(){
    for(int i=0; i<MAX; i++){
        graph[i].clear();
        match[i] = 0;
    }
}

bool visited[MAX];
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        reset();
        int n, m; cin >> n >> m;
        while(m--){
            int u, v; cin >> u >> v;
            graph[u+1].push_back(v+1);
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            fill(visited, visited+MAX, false);
            ans += dfs(i);
        }
        cout << ans << '\n';
    }
}
