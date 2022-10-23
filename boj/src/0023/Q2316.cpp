// BOJ 2316 [Traveling Cities Back and Forth 2]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 1
#define SNK 2
#define MAX 801

int flo[MAX][MAX], cap[MAX][MAX];
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

        // update flow
        for(int i=SNK; i!=SRC; i=prev[i]) flo[prev[i]][i]++, flo[i][prev[i]]--;
        mflo++;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, P; cin >> N >> P;

    // split vertices
    for(int i=3; i<=N; i++){
        adj[i].push_back(i+N);
        adj[i+N].push_back(i);
        cap[i][i+N] = 1;
    }

    // add edges
    while(P--){
        int a, b; cin >> a >> b;
        if(a == 1 || b == 1){ // source
            int dst = (a == 1 ? b : a);
            adj[SRC].push_back(dst);
            adj[dst].push_back(SRC);
            cap[SRC][dst] = 1;
        }
        else if(a == 2 || b == 2){ // sink
            int src = (a == 2 ? b : a);
            adj[src+N].push_back(SNK);
            adj[SNK].push_back(src+N);
            cap[src+N][SNK] = 1;
        }
        else{ // normal
            adj[a+N].push_back(b);
            adj[b].push_back(a+N);
            adj[b+N].push_back(a);
            adj[a].push_back(b+N);
            cap[a+N][b] = 1;
            cap[b+N][a] = 1;
        }
    }

    max_flow();
    cout << mflo;
}
