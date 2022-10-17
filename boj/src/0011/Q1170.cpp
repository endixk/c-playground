// BOJ 1170 [Number of Cacti]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 201

vector<int> graph[MAX];
bool visited[MAX];
int vcnt[MAX], parent[MAX];

bool cactus = true;
void dfs(int v, int p){
    vcnt[v]++;
    parent[v] = p;

    for(int n : graph[v]){
        if(visited[n]) continue;
        if(n == p) continue;
        if(vcnt[n]){ // cycle
            int cur = v;
            while(cur != parent[n]){
                if(vcnt[cur] == 2) cactus = false;
                vcnt[cur]++;
                cur = parent[cur];
            }
        }
        else dfs(n, v);
    }
    visited[v] = true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            cactus = true;
            dfs(i, 0);
            if(cactus) ans++;
        }
    }

    cout << ans;
}
