// BOJ 2419 [Candies]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 301
#define INF 999999999

int N, M;
int loc[MAX], dp[MAX][MAX][2]; // l, r, l/r
int solve(int l, int r, int lr, int k){
    if(k == 0) return 0;
    int &ret = dp[l][r][lr];
    if(ret != -1) return ret;

    ret = INF;
    if(l > 0){
        if(lr) ret = min(ret, k * (loc[r] - loc[l-1]) + solve(l-1, r, 0, k-1));
        else ret = min(ret, k * (loc[l] - loc[l-1]) + solve(l-1, r, 0, k-1));
    }
    if(r < N-1){
        if(lr) ret = min(ret, k * (loc[r+1] - loc[r]) + solve(l, r+1, 1, k-1));
        else ret = min(ret, k * (loc[r+1] - loc[l]) + solve(l, r+1, 1, k-1));
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M; bool zero = false;
    for(int i = 0; i < N; ++i) cin >> loc[i], zero |= loc[i] == 0;
    if(!zero) loc[N++] = 0;
    sort(loc, loc+N);

    // find zero
    int z = (int)(lower_bound(loc, loc+N, 0) - loc), ans = 0;
    for(int i=0; i<=N; i++){
        memset(dp, -1, sizeof(dp));
        ans = max(ans, M*i - solve(z, z, 0, i));
    }
    cout << ans + zero*M;
}
