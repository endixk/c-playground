// BOJ 1092 [Boat]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int L[N];
    for (int i = 0; i < N; i++) cin >> L[i];
    int M; cin >> M;
    int W[M];
    for (int i = 0; i < M; i++) cin >> W[i];

    sort(W, W+M, greater<>());
    int load[N];
    fill(load, load+N, 0);
    for(int w : W){
        int val = 1e9, idx = -1;
        for(int i = 0; i < N; i++){
            if(L[i] >= w && load[i] < val){
                val = load[i];
                idx = i;
            }
        }
        if(idx == -1) {
            cout << -1;
            return 0;
        }
        load[idx]++;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(ans, load[i]);
    cout << ans;
}
