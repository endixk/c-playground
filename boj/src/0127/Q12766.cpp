// BOJ 12766 [Branch Assignment]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5002
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f

int N, B, S, R;
vector<pair<int,int>> adj[MAX], rev[MAX];

int dist[MAX], rdst[MAX]; // distance from/to B+1
bool visited[MAX];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
void dijkstra(int s){
    for(int i=1; i<=N; i++) dist[i] = rdst[i] = INF;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(auto [next, cost] : adj[cur]){
            if(dist[next] > dist[cur] + cost){
                dist[next] = dist[cur] + cost;
                pq.push({dist[next], next});
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    rdst[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(auto [next, cost] : rev[cur]){
            if(rdst[next] > rdst[cur] + cost){
                rdst[next] = rdst[cur] + cost;
                pq.push({rdst[next], next});
            }
        }
    }
}

vector<pair<int,int>> dsum;
ll pref[MAX], dp[MAX], tmp[MAX];
void dnc(int s, int e, int l, int r){
    if(s > e) return;
    int m = (s+e)>>1, n = -1;
    dp[m] = LINF;
    for(int i=l; i<=r && i<=m; i++){
        ll cost = tmp[i] + (ll) (m-i-1) * (pref[m] - pref[i]);
        if(dp[m] > cost){
            dp[m] = cost;
            n = i;
        }
    }
    dnc(s, m-1, l, n);
    dnc(m+1, e, n, r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> B >> S >> R;
    for(int i=0; i<R; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        rev[v].emplace_back(u, w);
    }

    dijkstra(B+1);
    for(int i=1; i<=B; i++) dsum.emplace_back(dist[i]+rdst[i], i);
    sort(dsum.begin(), dsum.end());
    for(int i=0; i<B; i++) tmp[i+1] = LINF, pref[i+1] = pref[i] + dsum[i].first;
    for(int i=0; i<S; i++){
        dnc(i+1, B, 0, B);
        for(int j=0; j<=B; j++) tmp[j] = dp[j];
    }

    cout << dp[B];
}
