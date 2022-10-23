// BOJ 1420 [Don't Go to the School!]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 20201
#define MAX 20202
#define INF 999999999

struct Edge {
    int dst, flo, cap, rev;
    Edge(int dst, int flo, int cap, int rev) : dst(dst), flo(flo), cap(cap), rev(rev) {}
};
vector<Edge> adj[MAX];

// Edmonds-Karp
queue<int> Q;
int mflo;
void max_flow(){
    while(true){
        int prev[MAX], pidx[MAX];
        memset(prev, -1, sizeof(prev));
        memset(pidx, -1, sizeof(pidx));
        prev[SRC] = pidx[SRC] = SRC; Q.push(SRC);

        // find path
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int i=0; i<adj[cur].size(); i++){
                int nxt = adj[cur][i].dst;
                if(prev[nxt] == -1 && adj[cur][i].cap - adj[cur][i].flo > 0){
                    prev[nxt] = cur;
                    pidx[nxt] = i;
                    Q.push(nxt);
                    if(nxt == SNK) break;
                }
            }
        }
        if(prev[SNK] == -1) break;

        // find min-flow
        int flow = INF;
        for(int i=SNK; i!=SRC; i=prev[i]) flow = min(flow, adj[prev[i]][pidx[i]].cap - adj[prev[i]][pidx[i]].flo);

        // update flow
        for(int i=SNK; i!=SRC; i=prev[i]){
            adj[prev[i]][pidx[i]].flo += flow;
            adj[i][adj[prev[i]][pidx[i]].rev].flo -= flow;
        }
        mflo += flow;
    }
}

char board[101][101];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        string s; cin >> s;
        for(int j=1; j<=M; j++) board[i][j] = s[j-1];
    }

    // generate vertices
    int sz = N*M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(board[i][j] == '.'){
                int vi = i*M + j, vo = sz + vi;
                adj[vi].emplace_back(vo, 0, 1, adj[vo].size());
                adj[vo].emplace_back(vi, 0, 0, adj[vi].size()-1);
            }
        }
    }

    // connect vertices
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(board[i][j] == 'K'){ // source
                for(int k=0; k<4; k++){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni <= 0 || ni > N || nj <= 0 || nj > M) continue;
                    if(board[ni][nj] == '.') {
                        adj[SRC].emplace_back(ni*M + nj, 0, 1, adj[ni*M + nj].size());
                        adj[ni*M + nj].emplace_back(SRC, 0, 0, adj[SRC].size()-1);
                    }
                    else if(board[ni][nj] == 'H'){
                        cout << -1;
                        return 0;
                    }
                }
            }
            else if(board[i][j] == 'H'){ // sink
                for(int k=0; k<4; k++){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni <= 0 || ni > N || nj <= 0 || nj > M) continue;
                    if(board[ni][nj] == '.') {
                        adj[ni*M + nj + sz].emplace_back(SNK, 0, 1, adj[SNK].size());
                        adj[SNK].emplace_back(ni*M + nj + sz, 0, 0, adj[ni*M + nj + sz].size()-1);
                    }
                }
            }
            else {
                for(int k=0; k<4; k++){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni <= 0 || ni > N || nj <= 0 || nj > M) continue;
                    if(board[ni][nj] == '.') {
                        adj[i*M + j + sz].emplace_back(ni*M + nj, 0, 1, adj[ni*M + nj].size());
                        adj[ni*M + nj].emplace_back(i*M + j + sz, 0, 0, adj[i*M + j + sz].size()-1);
                    }
                }
            }
        }
    }

    max_flow();
    cout << mflo;
}
