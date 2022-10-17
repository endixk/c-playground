// BOJ 10891 [Cactus? Not Cactus?]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

vector<int> graph[MAX];
bool visited[MAX];
int vcnt[MAX], parent[MAX];

void dfs(int v, int p){
    vcnt[v]++;
    parent[v] = p;

    for(int n : graph[v]){
        if(visited[n]) continue;
        if(n == p) continue;
        if(vcnt[n]){ // cycle
            int cur = v;
            while(cur != parent[n]){
                if(vcnt[cur] == 2) {
                    cout << "Not cactus";
                    exit(0);
                }
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
    dfs(1, 0);
    cout << "Cactus";
}
