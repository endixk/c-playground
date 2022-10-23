// BOJ 1189 [Come Back Home]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int R, C, K, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char board[5][5];
bool visited[5][5];
int dfs(int x, int y, int d){
    if(x < 0 || x >= R || y < 0 || y >= C) return 0;
    if(board[x][y] == 'T') return 0;
    if(visited[x][y]) return 0;
    if(x == 0 && y == C-1) return d == K;
    if(d == K) return 0;

    visited[x][y] = true;
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        ret += dfs(nx, ny, d+1);
    }
    visited[x][y] = false;
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> board[i][j];
    cout << dfs(R-1, 0, 1);
}
