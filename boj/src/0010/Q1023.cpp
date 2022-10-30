// BOJ 1023 [Invalid Parentheses]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K, dp[51][101][2]; // cnt, state, flag
ll solve(int c, int s, bool f){
    if(c == N) return f | (s != 50);
    ll &ret = dp[c][s][f];
    if(ret != -1) return ret;

    ret = 0;
    ret += solve(c+1, s+1, f); // add '('
    ret += solve(c+1, s-1, f | (s == 50)); // add ')'
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    solve(0, 50, false);

    if(dp[0][50][0] < ++K) return cout << -1, 0;
    string ans;
    int s = 50; bool f = false;
    for(int i=0; i<N-1; i++){
        if(dp[i+1][s+1][f] >= K){
            ans += '(';
            s++;
        } else {
            ans += ')';
            K -= dp[i+1][s+1][f];
            f |= s == 50;
            s--;
        }
    }
    cout << ans + (K == 1 ? '(' : ')');
}
