// BOJ 1126 [Identical Towers]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int dp[51][500001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, HS = 0; cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i], HS += h[i];

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= HS; j++){
            if(dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+h[i]] = max(dp[i+1][j+h[i]], dp[i][j] + h[i]);
            dp[i+1][abs(j-h[i])] = max(dp[i+1][abs(j-h[i])], dp[i][j] + (h[i] > j ? h[i] - j : 0));
        }
    }

    cout << (dp[N][0] > 0 ? dp[N][0] : -1);
}
