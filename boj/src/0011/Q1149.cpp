// BOJ 1149 [RGB Avenue]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N, price[1001][3], dp[1001][3];

// 0: red; 1: green; 2: blue
int solve(int k, int c){
    if(k == 0) return price[k][c];
    int &ret = dp[k][c];
    if(ret != -1) return ret;

    ret = 1e9;
    for(int i=0; i<3; i++){
        if(i == c) continue;
        ret = min(ret, solve(k-1, i) + price[k][c]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++) cin >> price[i][0] >> price[i][1] >> price[i][2];
    memset(dp, -1, sizeof(dp));
    cout << min({solve(N-1, 0), solve(N-1, 1), solve(N-1, 2)});
}
