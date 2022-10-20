// BOJ 1176 [Shuffling]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
ll dp[1<<16][16], h[16];
bool diff[16][16];
ll solve(int mask, int last){
    if(mask == (1<<N)-1) return 1;
    ll &ret = dp[mask][last];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<N; i++){
        if(mask & (1<<i)) continue;
        if(diff[last][i]) ret += solve(mask | (1<<i), i);
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> h[i];
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) diff[i][j] = abs(h[i] - h[j]) > K;

    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for(int i=0; i<N; i++) ans += solve(1<<i, i);
    cout << ans;
}
