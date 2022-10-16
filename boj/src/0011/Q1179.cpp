// BOJ 1179 [The Final Josephus Problem]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll> m[99];
ll josephus(ll n, ll k){
    if(n == 1) return 0;
    if(k == 1) return n-1;
    if(m[k].find(n) != m[k].end()) return m[k][n];
    if(n < k) return (josephus(n-1, k) + k) % n;

    ll h = josephus(n - n/k, k) - n%k;
    if(h < 0) return h + n;
    return h + h/(k-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k; cin >> n >> k;
    cout << josephus(n, k) + 1;
}
