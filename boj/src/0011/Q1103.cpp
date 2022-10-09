// BOJ 1103 [Game]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[50][50];
bool visited[50][50];
int dp[50][50];
int dfs(int i, int j){
    if(visited[i][j]){
        cout << -1; exit(0);
    }
    if(dp[i][j] != -1) return dp[i][j];
    visited[i][j] = true;

    int ret = 0;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    for(int k=0; k<4; k++){
        int ni = i + di[k] * arr[i][j];
        int nj = j + dj[k] * arr[i][j];
        if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
        if(arr[ni][nj] == -1) continue;
        ret = max(ret, dfs(ni, nj));
    }

    visited[i][j] = false;
    return dp[i][j] = ret + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        for(int j=0; j<M; j++) {
            if(s[j] == 'H') arr[i][j] = -1;
            else arr[i][j] = s[j] - '0';
            visited[i][j] = false;
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);
}
