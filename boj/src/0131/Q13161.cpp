// BOJ 13161 [Sorrow of Division]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 501
#define MAX 502
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    for(int i=1; i<=N; i++){
        int t; cin >> t;
        switch(t){
            case 1:
                adj[SRC].push_back(i);
                adj[i].push_back(SRC);
                cap[SRC][i] = INF;
                break;
            case 2:
                adj[i].push_back(SNK);
                adj[SNK].push_back(i);
                cap[i][SNK] = INF;
                break;
            default: break;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int w; cin >> w;
            if(w > 0) {
                cap[i][j] = w;
                adj[i].push_back(j);
            }
        }
    }

    cout << dinic() << '\n';

    bool visited[MAX];
    memset(visited, false, sizeof(visited));
    Q.push(SRC);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt : adj[cur]){
            if(!visited[nxt] && cap[cur][nxt] - flo[cur][nxt] > 0){
                visited[nxt] = true;
                Q.push(nxt);
            }
        }
    }
    for(int i=1; i<=N; i++){
        if(visited[i]) cout << i << ' ';
    }
    cout << '\n';
    for(int i=1; i<=N; i++){
        if(!visited[i]) cout << i << ' ';
    }
    cout << '\n';
}
