// BOJ 11375 [Passionate Kang-ho]
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M; cin >> N >> M;
    for(int i=1,j,k; i<=N; i++){
        cin >> k;
        while(k--){
            cin >> j;
            graph[i].push_back(j);
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        fill(visited, visited+MAX, false);
        ans += dfs(i);
    }
    cout << ans;
}
