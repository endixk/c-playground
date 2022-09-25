// BOJ 1045 [Roads]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Union-Find
int parent[50];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) parent[i] = i;

    bool adj[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            adj[i][j] = false;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<N; j++)
            // add edge only if start < end
            if(i < j) adj[i][j] = (s[j] == 'Y');
    }

    // Kruskal's algorithm
    vector<pair<int, int>> accepted;
    vector<pair<int, int>> rejected;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(adj[i][j]){
                if(find(i) != find(j)){
                    uni(i, j);
                    accepted.emplace_back(i, j);
                }
                else rejected.emplace_back(i, j);
            }
        }
    }

    // check if all nodes are connected
    if(accepted.size() != N-1){
        cout << -1 << '\n';
        return 0;
    }

    // exception handling
    if(rejected.size() < M-N+1){
        cout << -1 << '\n';
        return 0;
    }

    // include rejected edges greedily
    for(int i=0; i<M-N+1; i++) accepted.push_back(rejected[i]);

    // print answer
    int conn[N];
    for(int i=0; i<N; i++) conn[i] = 0;
    for(auto [a, b] : accepted){
        conn[a]++;
        conn[b]++;
    }
    for(int i=0; i<N; i++) cout << conn[i] << ' ';
    cout << '\n';
}