// BOJ 1648 [Filling the Grid]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MOD 9901

int N, M, dp[200][1<<14];
int solve(int x, int bit){
    int &ret = dp[x][bit];
    if(ret != -1) return ret;

    ret = 0;
    if(x == N*M) return ret = (bit == 0);
    if(bit & 1) ret += solve(x+1, bit>>1);
    else{
        ret += solve(x+1, (bit>>1) | (1<<(M-1)));
        if(x%M != M-1 && !(bit & 2)) ret += solve(x+2, bit>>2);
    }
    return ret %= MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}
