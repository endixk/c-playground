// BOJ 1131 [Numbers]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1000001], pows[10];
bool visited[1000001];

ll next(ll x){
    ll ret = 0;
    while(x){
        ret += pows[x%10];
        x /= 10;
    }
    return ret;
}

ll find(ll x){
    if(x >= 1000000) return find(next(x));
    if(dp[x] != -1) return dp[x];

    // cycle
    if(visited[x]){
        // find cycle members and find min
        vector<ll> mem = {x};
        while(ll y = next(mem.back())){
            if(y == x) break;
            mem.push_back(y);
        }
        ll ret = *min_element(mem.begin(), mem.end());

        // fill table and return
        for(ll y : mem) if(y <= 1000000) dp[y] = ret;
        return ret;
    }

    visited[x] = true;
    return dp[x] = min(x, find(next(x)));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll A, B, K; cin >> A >> B >> K;
    for(int i=0; i<10; i++) pows[i] = (ll) pow(i, K);

    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    for(ll i=A; i<=B; i++) ans += find(i);
    cout << ans << endl;
}
