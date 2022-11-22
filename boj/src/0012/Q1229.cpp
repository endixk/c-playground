// BOJ 1229 [Hexagonal Number]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define INF 0x3f3f3f3f

vector<int> H;
int dp[MAX];
int solve(int n){
    if(n == 0) return 0;
    int &ret = dp[n];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=(int)(lower_bound(H.begin(), H.end(), n) - H.begin()); i>=0; i--){
        if(n - H[i] < 0) continue;
        ret = min(ret, solve(n - H[i]) + 1);
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;

    for(int h=1; h<=N; h += 4 * (int)H.size() + 1) H.push_back(h);
    memset(dp, -1, sizeof(dp));
    solve(N);
    cout << dp[N];
}
