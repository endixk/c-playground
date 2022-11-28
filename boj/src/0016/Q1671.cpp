// BOJ 1671 [Shark Dinner]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 101

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

vector<int> S, P, I;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    S.resize(N); P.resize(N); I.resize(N);
    for(int i=0; i<N; i++) cin >> S[i] >> P[i] >> I[i];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) continue;
            if(S[i] == S[j] && P[i] == P[j] && I[i] == I[j] && i < j) continue;
            if(S[i] >= S[j] && P[i] >= P[j] && I[i] >= I[j]) graph[i+1].push_back(N+j+1);
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        fill(visited, visited+MAX, false);
        if(dfs(i)) ans++;
        fill(visited, visited+MAX, false);
        if(dfs(i)) ans++;
    }
    cout << N-ans;
}
