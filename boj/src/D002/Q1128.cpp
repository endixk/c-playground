// BOJ 1128 [Fibonacci Knapsack]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, C, wsum[50], vsum[50];
vector<pair<ll,ll>> items;

ll solve(ll n, ll c, bool flag){
    if(n < 0) return 0;
    if(c >= wsum[n]) return vsum[n];
    if(c < items[n].first) return solve(n-1, c, true);
    if(flag && (items[n].first == items[n+1].first)) return solve(n-1, c, true);
    return max(solve(n-1, c, true), solve(n-1, c-items[n].first, false) + items[n].second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++){
        ll w, v; cin >> w >> v;
        items.emplace_back(w, v);
    }
    sort(items.begin(), items.end());

    wsum[0] = items[0].first;
    vsum[0] = items[0].second;
    for(int i=1; i<N; i++){
        wsum[i] = wsum[i-1] + items[i].first;
        vsum[i] = vsum[i-1] + items[i].second;
    }

    cin >> C;
    cout << solve(N-1, C, true);
}
