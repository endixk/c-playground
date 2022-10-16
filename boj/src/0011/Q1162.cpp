// BOJ 1162 [Revamping Trails]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
#define INF INT64_MAX
typedef long long ll;

ll N, M, K, dist[MAX][21];
bool visited[MAX][21];
vector<pair<ll,ll>> graph[10001];
priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<>> PQ;

void dijkstra(int s){
    for(auto &d : dist[s]) d = 0;
    PQ.emplace(0, make_pair(s, 0));

    while(!PQ.empty()){
        auto [d, p] = PQ.top(); PQ.pop();
        auto [u, k] = p;
        if(visited[u][k]) continue;
        visited[u][k] = true;
        dist[u][k] = d;
        for(auto [v, w] : graph[u]){
            // revamp
            if(k < K && dist[v][k+1] > dist[u][k]){
                dist[v][k+1] = dist[u][k];
                PQ.emplace(dist[v][k+1], make_pair(v, k+1));
            }
            // do not revamp
            if(dist[v][k] > dist[u][k] + w){
                dist[v][k] = dist[u][k] + w;
                PQ.emplace(dist[v][k], make_pair(v, k));
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 0; i < M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    for(int i = 1; i <= N; ++i)
        for(int j = 0; j <= K; ++j)
            dist[i][j] = INF;
    dijkstra(1);

    ll ans = INF;
    for(int i = 0; i <= K; ++i)
        ans = min(ans, dist[N][i]);
    cout << ans;
}
