// BOJ 1143 [Police Station]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 51
#define INF 9999

// Tarjan's algorithm
vector<int> graph[MAX], id(MAX);
stack<vector<int>> SCC;
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
        SCC.push(scc);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    int price[N];
    for(int i=0; i<N; i++) cin >> price[i];
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<N; j++){
            if(s[j] == 'Y') graph[i].push_back(j);
        }
    }

    // find SCC
    for(int i=0; i<N; i++) if(!id[i]) dfs(i);

    // find minimum cost for SCCs with no incoming edges
    int ans = 0, iter = 0;
    while(!SCC.empty()){
        vector<int> scc = SCC.top(); SCC.pop();

        // find incoming edges
        bool in = false;
        for(int u=0; u<N; u++){
            if(find(scc.begin(), scc.end(), u) != scc.end()) continue;
            for(int v : graph[u]){
                if(find(scc.begin(), scc.end(), v) != scc.end()){
                    in = true;
                    break;
                }
            }
            if(in) break;
        }
        if(in) continue;

        // find minimum cost
        int mc = INF, mi = -1;
        for(int u : scc) if(price[u] < mc) mc = price[u], mi = u;
        ans += mc;
        price[mi] = INF;
        iter++;
    }

    // update average
    sort(price, price+N);
    for(int p : price) {
        if(ans > p * iter) ans += p, iter++;
        else break;
    }
    cout << fixed << setprecision(15) << (double) ans / iter;
}
