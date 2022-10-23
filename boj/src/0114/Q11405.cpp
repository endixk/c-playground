// BOJ 11405 [Purchasing Books]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 201
#define MAX 202
#define INF 999999999

int N, M, val[MAX][MAX], flo[MAX][MAX], cap[MAX][MAX];
vector<int> adj[MAX];

// min-cost max-flow
queue<int> Q;
int cost;
void mcmf(){
    while(true){
        int prev[MAX], dist[MAX]; bool inQ[MAX];
        fill(prev, prev+MAX, -1);
        fill(dist, dist+MAX, INF);
        fill(inQ, inQ+MAX, false);
        dist[SRC] = prev[SRC] = 0; inQ[SRC] = true; Q.push(SRC);

        // SPFA
        while(!Q.empty()){
            int cur = Q.front(); Q.pop(); inQ[cur] = false;
            for(int nxt : adj[cur]){
                if(cap[cur][nxt] - flo[cur][nxt] > 0 && dist[nxt] > dist[cur] + val[cur][nxt]){
                    dist[nxt] = dist[cur] + val[cur][nxt];
                    prev[nxt] = cur;
                    if(!inQ[nxt]){
                        Q.push(nxt);
                        inQ[nxt] = true;
                    }
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
            cost += val[prev[i]][i] * flow;
        }
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
            cap[i][M+j] = INF;
            val[i][M+j] = c;
            val[M+j][i] = -c;
        }
    }

    mcmf();
    cout << cost;
}
