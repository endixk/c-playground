// BOJ 6549 [Largest Rectangle in a Histogram]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<pair<ll, ll>> S;
int N, H[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    S.emplace(0, 0);

    while(true) {
        cin >> N;
        if (!N) break;
        for (int i = 1; i <= N; i++) cin >> H[i];

        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            ll h = H[i], idx = i;
            while (S.top().first > h) {
                auto [ph, pi] = S.top();
                S.pop();
                ans = max(ans, ph * (i - pi));
                idx = pi;
            }
            S.emplace(h, idx);
        }
        while (S.size() > 1) {
            auto [ph, pi] = S.top();
            S.pop();
            ans = max(ans, ph * (N - pi + 1));
        }
        cout << ans << '\n';
    }
}
