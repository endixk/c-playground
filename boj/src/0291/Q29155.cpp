#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int N, DP[1004][1004], P[5];
vector<int> K[5];

int go(int i, int j, int p) {
    if(i == 0) return K[p][j];
    if(DP[i][j] > 0) return DP[i][j];
    int ret = INF;
    for(int k=0; k<j; k++) {
        int x = go(i-1, k, p);
        if (x == INF) continue;
        ret = min(ret, x + 2 * K[p][j] - K[p][k]);
    }
    return DP[i][j] = ret;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<5; i++) cin >> P[i];
    for(int i=0; i<N; i++) {
        int k, t; cin >> k >> t;
        K[k-1].push_back(t);
    }

    int ans = 0;
    for(int i=0; i<5; i++) {
        sort(K[i].begin(), K[i].end());
        int k = (int)K[i].size();
        for(int j=0; j<k; j++) fill(DP[j], DP[j]+k, 0);
        int a = INF;
        for(int j=0; j<k; j++) a = min(a, go(P[i]-1, j, i));
        ans += a;
    }
    cout << ans + 240 << '\n';
}
