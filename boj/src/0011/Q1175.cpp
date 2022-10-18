// BOJ 1175 [Delivery]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[51][51];
bool visited[51][51][4][3]; // 0: from N, 1: from E, 2: from S, 3: from W

pair<int,int> c1 = {-1, -1}, c2 = {-1, -1};
queue<tuple<int,int,int,int,int>> Q;
void bfs(int sx, int sy){
    Q.emplace(sx-1, sy, 0, 0, 1);
    Q.emplace(sx, sy-1, 1, 0, 1);
    Q.emplace(sx+1, sy, 2, 0, 1);
    Q.emplace(sx, sy+1, 3, 0, 1);
    while(!Q.empty()){
        tuple<int,int,int,int,int> cur = Q.front(); Q.pop();
        int x = get<0>(cur), y = get<1>(cur), dir = get<2>(cur), flag = get<3>(cur), cnt = get<4>(cur);
        if(x < 0 || x >= N || y < 0 || y >= M) continue;
        if(board[x][y] == '#') continue;
        if(visited[x][y][dir][flag]) continue;

        visited[x][y][dir][flag] = true;
        if(board[x][y] == 'C'){
            if(flag == 0){
                if(x == c1.first && y == c1.second) flag = 1;
                else flag = 2;
            }
            else if(flag == 1){
                if(x == c2.first && y == c2.second) {
                    cout << cnt;
                    exit(0);
                }
            }
            else if(flag == 2){
                if(x == c1.first && y == c1.second) {
                    cout << cnt;
                    exit(0);
                }
            }
        }

        if(dir != 0) Q.emplace(x-1, y, 0, flag, cnt+1);
        if(dir != 1) Q.emplace(x, y-1, 1, flag, cnt+1);
        if(dir != 2) Q.emplace(x+1, y, 2, flag, cnt+1);
        if(dir != 3) Q.emplace(x, y+1, 3, flag, cnt+1);
    }

    cout << -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    int x = 0, y = 0;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<M; j++){
            board[i][j] = s[j];
            if(board[i][j] == 'C'){
                if(c1.first == -1) c1 = {i, j};
                else c2 = {i, j};
            }
            else if(board[i][j] == 'S'){
                x = i, y = j;
            }
        }
    }
    bfs(x, y);
}
