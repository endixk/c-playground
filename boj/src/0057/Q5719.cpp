// BOJ 5719 [Almost Shortest Path]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[500];
vector<int> parent[500];
int dist[500];
bool visited[500];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;

void reset(bool hard){
    for(int i=0; i<500; i++){
        if(hard) graph[i].clear();
        if(hard) parent[i].clear();
        dist[i] = 1e9;
        visited[i] = false;
    }
}

void dijkstra(int s){
    dist[s] = 0;
    PQ.emplace(0, s);

    while(!PQ.empty()){
        int u = PQ.top().second; PQ.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [v, w] : graph[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                PQ.emplace(dist[v], v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if(dist[v] == dist[u] + w){
                parent[v].push_back(u);
            }
        }
    }
}

// erase by BFS
queue<int> Q;
void erase(int s, int u){
    memset(visited, false, sizeof(visited));
    Q.push(u);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        if(visited[v]) continue;
        visited[v] = true;
        if(v == s) continue;
        for(auto p : parent[v]){
            for(auto it = graph[p].begin(); it != graph[p].end(); it++){
                if(it->first == v){
                    graph[p].erase(it);
                    break;
                }
            }
            Q.push(p);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M, S, D;
    while(true){
        cin >> N >> M;
        if(!(N || M)) break;

        reset(true);
        cin >> S >> D;
        for(int i=0; i<M; i++){
            int u, v, p;
            cin >> u >> v >> p;
            graph[u].emplace_back(v, p);
        }
        dijkstra(S);
        erase(S, D);
        reset(false);
        dijkstra(S);
        cout << (dist[D] == 1e9 ? -1 : dist[D]) << '\n';
    }
}
