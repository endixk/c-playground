// BOJ 1194 [Full Moon is Rising]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

char board[51][51];
int N, M, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool visited[51][51][1<<6];

queue<tuple<int, int, int, int>> Q;
void bfs(int x, int y){
    Q.emplace(x, y, 0, 0);
    while(!Q.empty()){
        tuple<int,int,int,int> t = Q.front(); Q.pop();
        int i = get<0>(t), j = get<1>(t), k = get<2>(t), c = get<3>(t);
        if(i < 0 || i >= N || j < 0 || j >= M) continue;
        if(board[i][j] == '1') {
            cout << c; exit(0);
        }
        if(board[i][j] == '#') continue;
        if(isupper(board[i][j]) && !(k & (1 << (board[i][j] - 'A')))) continue;
        if(visited[i][j][k]) continue;
        visited[i][j][k] = true;
        if(islower(board[i][j])) k |= (1 << (board[i][j] - 'a'));
        for(int d = 0; d < 4; d++){
            Q.emplace(i + dx[d], j + dy[d], k, c+1);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    int x = 0, y = 0;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<M; j++){
            board[i][j] = s[j];
            if(board[i][j] == '0') x = i, y = j;
        }
    }
    bfs(x, y);
    cout << -1;
}
