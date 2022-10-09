// BOJ 2618 [Police Cars]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N, W;
pair<int, int> cases[1001];
int dist(int x, int y, bool car){
    pair<int,int> a = cases[x], b = cases[y];
    if(x == 0) a = car ? make_pair(1, 1) : make_pair(N, N);
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int dp[1001][1001], tx[1001][1001], ty[1001][1001];

int solve(int i, int j){
    if(dp[i][j] < 1e9) return dp[i][j];
    if(i == W || j == W) return 0;

    int d1 = dist(i, max(i, j) + 1, true) + solve(max(i, j) + 1, j);
    int d2 = dist(j, max(i, j) + 1, false) + solve(i, max(i, j) + 1);
    if(d1 < d2) dp[i][j] = d1, tx[i][j] = max(i, j) + 1;
    else dp[i][j] = d2, ty[i][j] = max(i, j) + 1;
    return dp[i][j];
}

void trace(int i, int j){
    if(i == W || j == W) return;
    if(tx[i][j] >= 0) cout << 1 << '\n', trace(tx[i][j], j);
    else cout << 2 << '\n', trace(i, ty[i][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> W;
    for(int i=1; i<=W; ++i) cin >> cases[i].first >> cases[i].second;

    for(int i=0; i<=W; ++i) for(int j=0; j<=W; ++j) dp[i][j] = 1e9;
    for(int i=0; i<=W; ++i) for(int j=0; j<=W; ++j) tx[i][j] = ty[i][j] = -1;
    cout << solve(0, 0) << '\n';
    trace(0, 0);
}
