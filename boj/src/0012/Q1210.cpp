// BOJ 1210 [Mafia]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 401
#define MAX 402
#define INF 2111111111

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

    int N, M; cin >> N >> M;
    int S, E; cin >> S >> E;

    // split vertices
    for(int i=1; i<=N; ++i){
        int v; cin >> v;
        adj[i].push_back(i+N);
        adj[i+N].push_back(i);
        cap[i][i+N] = v;
    }

    // connect source and sink
    adj[SRC].push_back(S);
    adj[S].push_back(SRC);
    cap[SRC][S] = INF;
    adj[E+N].push_back(SNK);
    adj[SNK].push_back(E+N);
    cap[E+N][SNK] = INF;

    // connect vertices
    for(int i=0; i<M; ++i){
        int u, v; cin >> u >> v;
        adj[u+N].push_back(v);
        adj[v].push_back(u+N);
        cap[u+N][v] = INF;
        adj[v+N].push_back(u);
        adj[u].push_back(v+N);
        cap[v+N][u] = INF;
    }

    dinic();

    // find vectices to block
    bool visited[MAX];
    fill(visited, visited+MAX, false);
    Q.push(SRC);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        visited[cur] = true;
        for(int nxt : adj[cur]){
            if(!visited[nxt] && cap[cur][nxt] - flo[cur][nxt] > 0) Q.push(nxt);
        }
    }
    for(int i=1; i<=N; i++){
        if(visited[i] && !visited[i+N]) cout << i << ' ';
    }
}