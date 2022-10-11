// BOJ 1135 [News Propagation]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[51];
bool visited[51];

int dfs(int n){
    visited[n] = true;

    int ret = 1;
    priority_queue<pair<int,int>> pq;
    for(int v : graph[n]) pq.push({dfs(v), v});

    int size = (int)pq.size();
    for(int i=1; i<=size; i++) ret = max(ret, pq.top().first + i), pq.pop();
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        int p; cin >> p;
        if(p != -1) graph[p].push_back(i);
    }
    cout << dfs(0)-1;
}
