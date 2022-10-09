// BOJ 1121 [Shapes]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
using namespace std;

long long dp[11][50002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int len[N];
    for (int i=0; i<N; i++) cin >> len[i];
    sort(len, len+N);
    int K, lmax = len[N-1]; cin >> K;

    long long ans = 0;
    dp[0][0] = 1;

    // calculate the number of K-sided shapes with len[x] as the longest side
    for(int k=0; k<N-1; k++){
        for(int i=K-2; i>=0; i--){
            for(int j=lmax+1; j>=0; j--){
                if(j+len[k] > lmax) dp[i+1][lmax+1] += dp[i][j];
                else dp[i+1][j+len[k]] += dp[i][j];
            }
        }
        for(int i=len[k+1]+1; i<=lmax+1; i++) ans += dp[K-1][i];
    }

    cout << ans;
}
