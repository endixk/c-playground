// BOJ 2533 [Social Media]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int dp[MAX][2];
vector<int> graph[MAX];
bool visited[MAX];
int dfs(int cur, bool early){
    if(dp[cur][early] != -1) return dp[cur][early];
    visited[cur] = true;
    int ret = 0;
    if(early){
        ret = 1;
        for(int next : graph[cur]){
            if(visited[next]) continue;
            ret += min(dfs(next, true), dfs(next, false));
        }
        visited[cur] = false;
        return dp[cur][early] = ret;
    } else {
        for(int next : graph[cur]){
            if(visited[next]) continue;
            ret += dfs(next, true);
        }
        visited[cur] = false;
        return dp[cur][early] = ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, u, v; cin >> N;
    for(int i=1; i<N; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) dp[i][0] = dp[i][1] = -1;
    cout << min(dfs(1, true), dfs(1, false));
    return 0;
}
