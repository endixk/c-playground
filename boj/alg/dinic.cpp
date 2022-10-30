// Maximum flow with Dinic's algorithm
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 1
#define MAX 2
#define INF 0x3f3f3f3f

int cap[MAX][MAX], flo[MAX][MAX], lvl[MAX], wrk[MAX];
vector<int> adj[MAX];
queue<int> Q;
bool dinic_bfs(){
    fill(lvl, lvl+MAX, -1);
    lvl[SRC] = 0; Q.push(SRC);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt : adj[cur]){
            if(lvl[nxt] == -1 && cap[cur][nxt] - flo[cur][nxt] > 0){
                lvl[nxt] = lvl[cur] + 1;
                Q.push(nxt);
            }
        }
    }
    return lvl[SNK] != -1;
}
int dinic_dfs(int cur, int flow){
    if(cur == SNK) return flow;
    for(int &i=wrk[cur]; i<adj[cur].size(); i++){
        int nxt = adj[cur][i];
        if(lvl[nxt] == lvl[cur] + 1 && cap[cur][nxt] - flo[cur][nxt] > 0){
            int df = dinic_dfs(nxt, min(flow, cap[cur][nxt] - flo[cur][nxt]));
            if(df > 0){
                flo[cur][nxt] += df;
                flo[nxt][cur] -= df;
                return df;
            }
        }
    }
    return 0;
}
int dinic(){
    int ret = 0;
    while(dinic_bfs()){
        fill(wrk, wrk+MAX, 0);
        while(true){
            int flow = dinic_dfs(SRC, INF);
            if(flow == 0) break;
            ret += flow;
        }
    }
    return ret;
}