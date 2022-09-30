// BOJ 1086 [PSW]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

// DP table
ll dp[1 << 15][101];

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S[N];
    for (int i = 0; i < N; i++) cin >> S[i];
    int K;
    cin >> K;

    // pre-processing
    int len[N], mod[N], ten[51];
    for (int i = 0; i < N; i++) {
        len[i] = S[i].length();
        mod[i] = 0;
        for (int j = 0; j < len[i]; j++) {
            mod[i] = (mod[i] * 10 + S[i][j] - '0') % K;
        }
    }
    ten[0] = 1;
    for (int i = 1; i <= 50; i++) ten[i] = (ten[i - 1] * 10) % K;

    // DP
    dp[0][0] = 1;
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < K; j++) {
            if (dp[i][j] == 0) continue;
            for (int k = 0; k < N; k++) {
                if (i & (1 << k)) continue;
                dp[i | (1 << k)][(j * ten[len[k]] + mod[k]) % K] += dp[i][j];
            }
        }
    }

    ll fact = 1;
    for (int i = 2; i <= N; i++) fact *= i;
    ll g = gcd(dp[(1 << N) - 1][0], fact);
    cout << dp[(1 << N) - 1][0] / g << '/' << fact / g;
}
