// BOJ 1017 [Prime Pairs]
// Supported by GitHub Copilot

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

// sieve of erathosthenes
bool era[2001];
void sieve(){
    for(bool & i : era) i = true;
    era[0] = era[1] = false;
    for(int i=2; i<=2000; i++)
        if(era[i]) for(int j=i+i; j<=2000; j+=i) era[j] = false;
}
int N;
bool adj[51][51];
bool bipartite(int n, bool *visited, int *dst, int *src){
    if(visited[n]) return false;
    visited[n] = true;
    for(int i=0; i<N; i++){
        if(adj[n][i]){
            if(dst[i] == -1 || bipartite(dst[i], visited, dst, src)){
                dst[i] = n;
                src[n] = i;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();

    cin >> N;
    int arr[N];
    for(int i=0; i<N; i++) cin >> arr[i];

    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            adj[i][j] = adj[j][i] = era[arr[i]+arr[j]];

    bool visited[N];
    int dst[N], src[N];
    vector<int> ans;
    for(int i=1; i<N; i++){
        if(!adj[0][i]) continue;

        memset(dst, -1, sizeof(dst));
        memset(src, -1, sizeof(src));

        int cnt = 1;
        src[0] = i;
        dst[i] = 0;

        for(int j=1; j<N; j++){
            memset(visited, false, sizeof(visited));
            visited[0] = true;
            if(bipartite(j, visited, dst, src)) cnt++;
        }

        if(cnt == N) ans.push_back(arr[i]);
    }

    if(ans.empty()) cout << -1;
    else{
        sort(ans.begin(), ans.end());
        for(int i : ans) cout << i << ' ';
    }
    cout << '\n';
}
