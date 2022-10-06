// BOJ 1119 [Graph]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

bool g[50][50], v[50];
int N, clu = 0; // number of clusters

int dfs(int n){
    v[n] = true;
    int cnt = 1;
    for(int i=0; i<N; i++){
        if(g[n][i] && !v[i]) cnt += dfs(i);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    int E = 0; // number of edges
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<N; j++){
            g[i][j] = s[j] == 'Y';
            if(g[i][j]) E++;
        }
    }
    E /= 2;

    if(E < N-1){
        cout << -1;
        return 0;
    }
    if(N == 1){
        cout << 0;
        return 0;
    }

    // get the number of clusters by DFS
    for(int i=0; i<N; i++){
        if(!v[i]){
            // impossible if isolated node exists
            if(dfs(i) < 2){
                cout << -1;
                return 0;
            }
            clu++;
        }
    }

    cout << clu-1;
}
