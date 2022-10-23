// BOJ 3640 [Admiral]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 0
#define SNK 2001
#define MAX 2002
#define INF 999999999

struct Edge {
    int dst, flo, cap, val, rev;
    Edge(int dst, int flo, int cap, int val, int rev) : dst(dst), flo(flo), cap(cap), val(val), rev(rev) {}
};
vector<Edge> adj[MAX];
int V, E, cost;

void reset(){
    cost = 0;
    for(auto & v : adj) v.clear();
}

// min-cost max-flow
queue<int> Q;
void mcmf(){
    for(int x=0; x<2; x++){
        int pre[MAX], pid[MAX], dis[MAX]; bool inq[MAX];
        fill(pre, pre+MAX, -1);
        fill(pid, pid+MAX, -1);
        fill(dis, dis+MAX, INF);
        fill(inq, inq+MAX, false);
        dis[SRC] = pre[SRC] = pid[SRC] = 0; inq[SRC] = true; Q.push(SRC);

        // SPFA
        while(!Q.empty()){
            int cur = Q.front(); Q.pop(); inq[cur] = false;
            for(int i = 0; i < (int)adj[cur].size(); i++){
                int nxt = adj[cur][i].dst;
                if(adj[cur][i].cap - adj[cur][i].flo > 0 && dis[nxt] > dis[cur] + adj[cur][i].val){
                    dis[nxt] = dis[cur] + adj[cur][i].val;
                    pre[nxt] = cur;
                    pid[nxt] = i;
                    if(!inq[nxt]){
                        Q.push(nxt);
                        inq[nxt] = true;
                    }
                }
            }
        }
        if(pre[SNK] == -1) break;

        // find min-flow
        int flow = INF;
        for(int i=SNK; i!=SRC; i=pre[i]) flow = min(flow, adj[pre[i]][pid[i]].cap - adj[pre[i]][pid[i]].flo);

        // update flow
        for(int i=SNK; i!=SRC; i=pre[i]){
            adj[pre[i]][pid[i]].flo += flow;
            adj[i][adj[pre[i]][pid[i]].rev].flo -= flow;
            cost += adj[pre[i]][pid[i]].val * flow;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    while(cin >> V >> E) {
        reset();

        // split vertices
        for(int i=1; i<V; i++){
            adj[i].emplace_back(i+V, 0, 1, 0, adj[i+V].size());
            adj[i+V].emplace_back(i, 0, 0, 0, adj[i].size()-1);
        }

        // add edges
        for(int i=0; i<E; i++){
            int a, b, c; cin >> a >> b >> c;
            if(a == 1 && b == V){ // source to sink
                adj[SRC].emplace_back(SNK, 0, 1, c, adj[SNK].size());
                adj[SNK].emplace_back(SRC, 0, 0, -c, adj[SRC].size()-1);
            } else if(a == 1){ // source to vertex
                adj[SRC].emplace_back(b, 0, 1, c, adj[b].size());
                adj[b].emplace_back(SRC, 0, 0, -c, adj[SRC].size()-1);
            } else if(b == V){ // vertex to sink
                adj[a+V].emplace_back(SNK, 0, 1, c, adj[SNK].size());
                adj[SNK].emplace_back(a, 0, 0, -c, adj[a+V].size()-1);
            } else { // vertex to vertex
                adj[a+V].emplace_back(b, 0, 1, c, adj[b].size());
                adj[b].emplace_back(a+V, 0, 0, -c, adj[a+V].size()-1);
            }
        }

        mcmf();
        cout << cost << '\n';
    }
}
