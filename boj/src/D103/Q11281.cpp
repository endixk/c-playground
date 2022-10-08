// BOJ 11281 [2-SAT - 4]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 20001

// Tarjan's algorithm
vector<int> graph[MAX], id(MAX);
vector<vector<int>> SCC;
bool visited[MAX];
stack<int> S;
int cnt = 0;
int dfs(int cur){
    visited[cur] = true;
    int ret = id[cur] = ++cnt;
    S.push(cur);
    for(int nxt : graph[cur]){
        if(!id[nxt]) ret = min(ret, dfs(nxt));
        else if(visited[nxt]) ret = min(ret, id[nxt]);
    }
    if(ret == id[cur]){
        vector<int> scc;
        while(true){
            int t = S.top(); S.pop();
            scc.push_back(t);
            visited[t] = false;
            id[t] = MAX;
            if(t == cur) break;
        }
        SCC.push_back(scc);
    }
    return ret;
}

int N;
int node(int x) {
    return x > 0 ? x : -x + N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int M; cin >> N >> M;

    // generate graph
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        graph[node(-a)].push_back(node(b));
        graph[node(-b)].push_back(node(a));
    }

    // define SCC
    for(int i=1; i<=2*N; i++) if(!id[i]) dfs(i);

    // check contradiction
    for(auto scc : SCC) {
        for (int v: scc) {
            if (v > N) continue;
            if (find(scc.begin(), scc.end(), v + N) != scc.end()) {
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1 << '\n';

    // assign boolean values
    vector<bool> ans(N+1, false);
    memset(visited, false, sizeof(visited));
    for(int i = SCC.size() - 1; i >= 0; i--){
        if(visited[SCC[i][0]]) continue;
        // assign false
        for(int v : SCC[i]) {
            if(v > N) {
                ans[v-N] = true;
                visited[v-N] = true;
            }
            else{
                ans[v] = false;
                visited[v+N] = true;
            }
            visited[v] = true;
        }
    }

    for(int i=1; i<=N; i++) cout << ans[i] << ' ';
}
