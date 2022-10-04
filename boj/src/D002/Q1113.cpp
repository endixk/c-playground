// BOJ 1113 [Swimming Pool]
// Supported by GitHub Copilot

#include <iostream>
#include <queue>
using namespace std;

int N, M, map[52][52];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
queue<pair<int,int>> q;

void enclose(int x, int y, int h){
    map[x][y] = h;
    q.emplace(x,y);

    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx > N+1 || ny < 0 || ny > M+1) continue;
            if(map[nx][ny] < h){
                map[nx][ny] = h;
                q.emplace(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    int maxh = 0;
    for(int i=1; i<=N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            map[i][j] = s[j - 1] - '0';
            maxh = max(maxh, map[i][j]);
        }
    }

    int ans = 0;
    for(int h = 2; h <= maxh; h++){
        enclose(0, 0, h);
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(map[i][j] == h-1) {
                    ans++;
                    map[i][j] = h;
                }
            }
        }
    }

    cout << ans;
}
