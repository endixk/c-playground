// BOJ 11378 [Passionate Kang-ho 4]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<int> graph[MAX];
int match[MAX];
bool visited[MAX];

// bipartite matching
bool dfs(int u){
    for(int v: graph[u]){
        if(visited[v]) continue;
        visited[v] = true;
        if(match[v] == 0 || dfs(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}

vector<pair<int,vector<int>>> works;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M, K; cin >> N >> M >> K;
    for(int i=1,j; i<=N; i++){
        cin >> j;
        vector<int> v(j);
        for(int &x: v) cin >> x;
        works.emplace_back(j, v);
    }
    sort(works.begin(), works.end());
    for(int i=1; i<=N; i++){
        for(auto v : works[i-1].second){
            graph[i].push_back(v);
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        fill(visited, visited+MAX, false);
        ans += dfs(i);
    }
    for(int i=1; i<=N; i++){
        while(K > 0){
            fill(visited, visited+MAX, false);
            if(dfs(i)) ans++, K--;
            else break;
        }
    }
    cout << ans;
}
