// BOJ 1127 [Rice Cake Republic]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

#define SRC 50
#define SNK 51
#define MAX 52

vector<int> graph[MAX];
queue<int> Q;
int N, K, cap[MAX][MAX], flo[MAX][MAX];

void reset(){
    for(auto v : graph) v.clear();
    memset(cap, 0, sizeof(cap));
    memset(flo, 0, sizeof(flo));
}

void add_edge(int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Edmonds-Karp algorithm
int max_flow(int src, int snk){
    int total = 0;

    while(true){
        vector<int> parent(MAX, -1);
        while(!Q.empty()) Q.pop();
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

        int flow = 1e9;
        for(int i = snk; i != src; i = parent[i]){
            flow = min(flow, cap[parent[i]][i] - flo[parent[i]][i]);
        }
        for(int i = snk; i != src; i = parent[i]){
            flo[parent[i]][i] += flow;
            flo[i][parent[i]] -= flow;
        }
        total += flow;
    }

    return total;
}

bool adj[MAX][MAX];
bool guard[MAX][MAX], office[MAX][MAX];

// generate network
void generate(int k){
    reset();
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(adj[i][j]){
                // guard: source; no office: sink
                int u, v;
                if(guard[i][k]) u = SRC;
                else if(!office[i][k]) u = SNK;
                else u = i;
                if(guard[j][k]) v = SRC;
                else if(!office[j][k]) v = SNK;
                else v = j;

                if(u == SRC){
                    if(v == SRC) continue;
                    else add_edge(u, v), cap[u][v]++;
                }
                else if(u == SNK){
                    if(v == SNK) continue;
                    else add_edge(u, v), cap[v][u]++;
                }
                else{
                    if(v == SRC) add_edge(u, v), cap[v][u]++;
                    else if(v == SNK) add_edge(u, v), cap[u][v]++;
                    else add_edge(u, v), cap[u][v]++, cap[v][u]++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    memset(adj, false, sizeof(adj));
    for(int i=0; i<N; ++i){
        string s; cin >> s;
        for(int j=0; j<N; ++j) adj[i][j] = s[j] == '1';
    }
    cin >> K;

    memset(guard, false, sizeof(guard));
    for(int i=0; i<N; i++){
        int j; cin >> j;
        while(j--){
            int k; cin >> k;
            guard[i][k] = true;
        }
    }

    memset(office, false, sizeof(office));
    for(int i=0; i<N; i++){
        int j; cin >> j;
        while(j--){
            int k; cin >> k;
            office[i][k] = true;
        }
    }

    int ans = 0;
    for(int k=0; k<K; k++){
        generate(k);
        ans += max_flow(SRC, SNK);
    }
    cout << ans;
}
