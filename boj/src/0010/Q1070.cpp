// BOJ 1070 [Invasion]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 5001
#define MAX 5002
#define PAD 10000000
#define INF 999999999
typedef long long ll;

struct Edge {
    int dst, flo, cap, rev;
    Edge(int dst, int flo, int cap, int rev) : dst(dst), flo(flo), cap(cap), rev(rev) {}
};
vector<Edge> adj[MAX];

// Edmonds-Karp
queue<int> Q;
ll mflo;
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
        for(int i=SNK; i!=SRC; i=prev[i])
            flow = min(flow, adj[prev[i]][pidx[i]].cap - adj[prev[i]][pidx[i]].flo);

        // update flow
        for(int i=SNK; i!=SRC; i=prev[i]){
            adj[prev[i]][pidx[i]].flo += flow;
            adj[i][adj[prev[i]][pidx[i]].rev].flo -= flow;
        }
        mflo += flow;
    }
}

char board[51][51];
int cost[26];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<M; j++) board[i][j] = s[j];
    }
    for(int& c : cost) cin >> c;

    // split vertices
    int sz = N*M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(board[i-1][j-1] == '-') continue;
            int k = (i-1)*M+j;
            int cap = (board[i-1][j-1] == '*') ? INF : cost[board[i-1][j-1]-'A'] + PAD;
            adj[k].emplace_back(k+sz, 0, cap, adj[k+sz].size());
            adj[k+sz].emplace_back(k, 0, 0, adj[k].size()-1);
            if(board[i-1][j-1] == '*') {
                adj[k+sz].emplace_back(SNK, 0, INF, adj[SNK].size());
                adj[SNK].emplace_back(k+sz, 0, 0, adj[k+sz].size()-1);
            }
        }
    }

    // connect source
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(i != 1 && i != N && j != 1 && j != M) continue;
            if(board[i-1][j-1] == '-') continue;
            int k = (i-1)*M+j;
            adj[SRC].emplace_back(k, 0, INF, adj[k].size());
            adj[k].emplace_back(SRC, 0, 0, adj[SRC].size()-1);
        }
    }

    // connect vertices
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(board[i-1][j-1] == '-') continue;
            if(board[i-1][j-1] == '*') continue;
            int k = (i-1)*M+j;
            for(int d=0; d<4; d++){
                int ni = i+dx[d], nj = j+dy[d];
                if(ni < 1 || ni > N || nj < 1 || nj > M) continue;
                if(board[ni-1][nj-1] == '-') continue;
                int nk = (ni-1)*M+nj;
                adj[k+sz].emplace_back(nk, 0, INF, adj[nk].size());
                adj[nk].emplace_back(k+sz, 0, 0, adj[k+sz].size()-1);
            }
        }
    }

    max_flow();
    cout << mflo % PAD;
}
