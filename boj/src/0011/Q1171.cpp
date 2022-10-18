// BOJ 1171 [Transmission Delay]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MOD 100000000
#define MAX 2001

int N, D, K, cz, co;
int pz[MAX], po[MAX], dp[MAX][MAX];
bool exceed[MAX][MAX];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> D >> K;
    string bit; cin >> bit;
    for(int i=0; i<N; i++){
        if(bit[i] == '0') pz[++cz] = i;
        else po[++co] = i;
    }

    dp[N][cz] = 1;
    for(int n=N-1; n>=0; n--){
        for(int z=0; z<=n; z++){
            if(z < cz && abs(pz[z+1] - n) <= D) {
                if(exceed[n+1][z+1] || dp[n][z] + dp[n+1][z+1] >= MOD) exceed[n][z] = true;
                dp[n][z] = (dp[n][z] + dp[n+1][z+1]) % MOD;
            }
            if(n-z < co && abs(po[n-z+1] - n) <= D) {
                if(exceed[n+1][z] || dp[n][z] + dp[n+1][z] >= MOD) exceed[n][z] = true;
                dp[n][z] = (dp[n][z] + dp[n+1][z]) % MOD;
            }
        }
    }

    string res; int z = 0;
    for(int n=0; n<N; n++){
        if(z < cz && abs(pz[z+1] - n) <= D && (exceed[n+1][z+1] || K <= dp[n+1][z+1])) {
            res += '0';
            z++;
        }
        else {
            res += '1';
            if(z < cz && abs(pz[z+1] - n) <= D) K -= dp[n+1][z+1];
        }
    }
    cout << dp[0][0] << '\n';
    cout << res;
}
