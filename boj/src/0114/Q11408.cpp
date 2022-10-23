// BOJ 11408 [Passionate Kang-ho 5]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 801
#define MAX 802
#define INF 999999999

int N, M, val[MAX][MAX], flo[MAX][MAX], cap[MAX][MAX];
vector<int> adj[MAX];

// min-cost max-flow
queue<int> Q;
int cost, jobs;
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
        jobs++;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        int k; cin >> k;
        while(k--){
            int j, v; cin >> j >> v;
            cap[i][j+N] = 1;
            adj[i].push_back(j+N);
            adj[j+N].push_back(i);
            val[i][j+N] = v;
            val[j+N][i] = -v;
        }
    }
    // connect source
    for(int i=1; i<=N; i++){
        cap[SRC][i] = 1;
        adj[SRC].push_back(i);
        adj[i].push_back(SRC);
    }
    // connect sink
    for(int i=1; i<=M; i++){
        cap[i+N][SNK] = 1;
        adj[i+N].push_back(SNK);
        adj[SNK].push_back(i+N);
    }

    mcmf();
    cout << jobs << ' ' << cost;
}
