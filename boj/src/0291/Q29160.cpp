#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> P[11];
bool go(int x, int p) {
    int c = 0;
    for(int i=0; i<(int)P[p].size(); i++) {
        if(P[p][i] < x) break;
        c += P[p][i] - x + 1;
        if(c >= K) return true;
    }
    return false;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        int p, w; cin >> p >> w;
        P[--p].push_back(w);
    }
    for(int i=0; i<11; i++) sort(P[i].begin(), P[i].end(), greater<int>());

    int ans = 0; ++K;
    for(int i=0; i<11; i++) {
        if(P[i].empty()) continue;
        int l = 0, r = 1e9;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(go(m, i)) l = m + 1;
            else r = m - 1;
        }
        ans += r;
    }
    cout << ans << '\n';
}
