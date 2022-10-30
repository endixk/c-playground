// BOJ 1056 [Number]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll> M;

ll p(ll x, int y){
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) {
        ll t = p(x, y / 2);
        return t * t;
    }
    return x * p(x, y - 1);
}
ll f(ll n, int x){
    ll l = 1, r = n;
    while(l<r){
        ll m = (l+r)/2;
        if(x * log2(m) < log2(n)) l = m+1;
        else r = m;
    }
    return l;
}

ll dp(ll n){
    if(n == 1) return 0;
    ll &ret = M[n];
    if(ret) return ret;

    ret = n-1;
    for(int x=2; x<62; x++){
        ll a = f(n, x);
        ret = min(ret, dp(a) + abs(p(a, x) - n) + 1);
        ret = min(ret, dp(a-1) + abs(n - p(a-1, x)) + 1);
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N; cin >> N;
    cout << dp(N);
}
