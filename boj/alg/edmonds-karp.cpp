// Edmonds-Karp algorithm
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 1
#define MAX 2
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