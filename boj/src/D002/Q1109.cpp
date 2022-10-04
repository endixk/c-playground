// BOJ 1109 [Islands]
// Supported by GitHub Copilot

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> graph[3000];
bool visited[52][52];
int nmap[52][52], N, M, isle = 0, iter;
char cmap[52][52];

// flood fill islands (hor, ver, diag)
void floodIsland(int x, int y, int i){
    if(visited[x][y]) return;
    visited[x][y] = true;
    nmap[x][y] = i;

    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1},
        dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    for(int k=0; k<8; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(cmap[nx][ny] == 'x') floodIsland(nx, ny, i);
    }
}

// flood fill water (hor, ver)
void floodWater(int x, int y, int i){
    if(visited[x][y]) return;
    visited[x][y] = true;
    nmap[x][y] = i;

    int dx[4] = {0, 0, 1, -1},
        dy[4] = {1, -1, 0, 0};
    for(int k=0; k<4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(nx < 0 || nx >= N+2 || ny < 0 || ny >= M+2) continue; // edge
        if(cmap[nx][ny] == '.') floodWater(nx, ny, i); // water
        else if(cmap[nx][ny] == 'x'){ // connect island
            if(graph[i].find(nmap[nx][ny]) == graph[i].end())
                graph[i].insert(nmap[nx][ny]);
            if(graph[nmap[nx][ny]].find(i) == graph[nmap[nx][ny]].end())
                graph[nmap[nx][ny]].insert(i);
        }
    }
}

bool ivis[3000];
int height[3000];
int dfs(int x){
    if(ivis[x]) return 0;
    ivis[x] = true;

    int h = 0;
    for(int i : graph[x]) h = max(h, dfs(i));
    return height[x] = h + (x < isle);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N + 2; i++) { // water padding
        for (int j = 0; j < M + 2; j++) {
            cmap[i][j] = '.';
            nmap[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
            cmap[i][j] = s[j - 1];
    }

    // find islands
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (cmap[i][j] == 'x' && !visited[i][j])
                floodIsland(i, j, isle++);
    iter = isle;

    // process water tiles
    for (int i = 0; i < N+2; i++)
        for (int j = 0; j < M+2; j++)
            if (cmap[i][j] == '.' && !visited[i][j])
                floodWater(i, j, iter++);

    dfs(isle);
    int hcnt[3000], hmax = 0;
    fill(hcnt, hcnt+3000, 0);
    for(int i=0; i<isle; i++){
        hcnt[height[i]-1]++;
        hmax = max(hmax, height[i]);
    }
    if(hmax == 0) cout << -1;
    else for(int i=0; i<hmax; i++) cout << hcnt[i] << ' ';
}
