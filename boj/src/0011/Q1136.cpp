// BOJ 1136 [Puzzle Pieces]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define INF 9999

// j: number of pieces used
// k: sum of the lengths of the used pieces
// val: minimum length among the remaining pieces
int dp[51][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int L, N; cin >> L >> N;
    int len[N+1];
    for(int i=0; i<N; i++) cin >> len[i];
    len[N] = INF;
    sort(len, len+N+1);

    // initialize dp
    for(int j=0; j<=N; j++)
        for(int k=0; k<=L; k++)
            dp[j][k] = -1;
    dp[0][0] = len[0];

    // calculate dp
    for(int i=0; i<N; i++){
        for(int j=N; j>=0; j--){
            for(int k=L; k>=0; k--){
                if(dp[j][k] < 0) continue;
                // use the i-th piece
                if(j < N && k + len[i] <= L) dp[j+1][k+len[i]] = i == j ? len[i+1] : max(dp[j][k], dp[j+1][k+len[i]]);
            }
        }
    }

    // get the answer
    for(int j=0; j<=N; j++){
        for(int k=0; k<=L; k++){
            if(dp[j][k] < 0) continue;
            if(L - k < dp[j][k] * (j + 1)) return cout << j, 0;
        }
    }
}
