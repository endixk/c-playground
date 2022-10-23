// BOJ 17142 [Traveling Cities Back and Forth]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SRC 1
#define SNK 2
#define MAX 401

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
    while(P--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = 1;
    }
    max_flow();
    cout << mflo;
}
