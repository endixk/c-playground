// Edmonds-Karp algorithm
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 1
#define MAX 2
#define INF 999999999

int N, M, flo[MAX][MAX], cap[MAX][MAX];
vector<int> adj[MAX];

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