// BOJ 1031 [StarCraft Matchup]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SRC 100
#define SNK 101
#define MAX 102

vector<int> graph[MAX];
queue<int> Q;
int N, M, cap[MAX][MAX], flo[MAX][MAX];

void add_edge(int u, int v, int c){
    graph[u].push_back(v);
    graph[v].push_back(u);
    cap[u][v] = c;
}

// Ford-Fulkerson algorithm
int max_flow(int src, int snk){
    int total = 0;

    while(true){
        vector<int> parent(MAX, -1);
        Q.push(src);

        while(!Q.empty() && parent[snk] == -1){
            int cur = Q.front(); Q.pop();
            for(int nxt : graph[cur]){
                if(cap[cur][nxt] - flo[cur][nxt] > 0 && parent[nxt] == -1){
                    parent[nxt] = cur;
                    Q.push(nxt);
                    if(nxt == snk) break;
                }
            }
        }
        if(parent[snk] == -1) break;

        for(int i = snk; i != src; i = parent[i]){
            flo[parent[i]][i]++;
            flo[i][parent[i]]--;
        }
        total++;
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> N >> M;

    // connect source to players of team 1
    for(int i = 0; i < N; i++) cin >> t, add_edge(SRC, i, t);
    // connect players of team 2 to sink
    for(int j = 0; j < M; j++) cin >> t, add_edge(N+j, SNK, t);
    // connect players of team 1 to players of team 2
    for(int i = 0; i < N; i++) for(int j = N+i; j < N+M; j++) add_edge(i, j, 1);

    // find maximum flow
    if(max_flow(SRC, SNK) )
}
