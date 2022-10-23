// BOJ 11406 [Purchasing Books 2]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 201
#define MAX 202
#define INF 999999999

int N, M, val[MAX][MAX], flo[MAX][MAX], cap[MAX][MAX];
vector<int> adj[MAX];

// Edmonds-Karp
queue<int> Q;
int mflo;
void max_flow(){
    while(true){
        int prev[MAX];
        memset(prev, -1, sizeof(prev));
        prev[SRC] = SRC; Q.push(SRC);

        // find path
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int nxt : adj[cur]){
                if(prev[nxt] == -1 && cap[cur][nxt] - flo[cur][nxt] > 0){
                    prev[nxt] = cur;
                    Q.push(nxt);
                    if(nxt == SNK) break;
                }
            }
        }
        if(prev[SNK] == -1) break;

        // find min-flow
        int flow = INF;
        for(int i=SNK; i!=SRC; i=prev[i]) flow = min(flow, cap[prev[i]][i] - flo[prev[i]][i]);

        // update flow
        for(int i=SNK; i!=SRC; i=prev[i]){
            flo[prev[i]][i] += flow;
            flo[i][prev[i]] -= flow;
        }
        mflo += flow;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    // connect customers to sink
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        adj[M+i].push_back(SNK);
        adj[SNK].push_back(M+i);
        cap[M+i][SNK] = a;
    }
    // connect source to bookstores
    for(int i=1; i<=M; i++){
        int b; cin >> b;
        adj[SRC].push_back(i);
        adj[i].push_back(SRC);
        cap[SRC][i] = b;
    }
    // connect bookstores to customers
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            int c; cin >> c;
            adj[i].push_back(M+j);
            adj[M+j].push_back(i);
            cap[i][M+j] = c;
        }
    }

    max_flow();
    cout << mflo;
}
