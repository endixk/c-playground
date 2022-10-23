// BOJ 11377 [Passionate Kang-ho 3]
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
    int N, M, K; cin >> N >> M >> K;
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
    int cnt = 0;
    for(int i=1; i<=N; i++){
        fill(visited, visited+MAX, false);
        if(dfs(i)) ans++, cnt++;
        if(cnt == K) break;
    }
    cout << ans;
}
