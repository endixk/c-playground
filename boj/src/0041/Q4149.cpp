// BOJ 4149 [Factorizing a Big Number]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;

inline ll mul(ll a, ll b, ll m) {
    return (ll)((lll)a * b % m);
}

ll power(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = mul(ret, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return ret;
}

bool miller(ll n, ll a) {
    if (n == a) return true;
    ll d = n - 1;
    while (!(d & 1)) {
        if (power(a, d, n) == n - 1) return true;
        d >>= 1;
    }
    ll tmp = power(a, d, n);
    return tmp == n - 1 || tmp == 1;
}

const int TP[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool isPrime(ll n){
    if(n < 2) return false;
    for(int p : TP){
        if(n == p) return true;
        if(!miller(n, p)) return false;
    }
    return true;
}

ll gcd(ll a, ll b) {
    while (b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

vector<ll> factors;
inline ll rint(ll n){
    return rand() % (n - 2) + 2;
}
void pollard_rho(ll n){
    if(n == 1) return;
    for(int p : TP){
        if(n % p == 0){
            factors.push_back(p);
            pollard_rho(n / p);
            return;
        }
    }
    if(isPrime(n)){
        factors.push_back(n);
        return;
    }
    ll x = rint(n), y = x, c = rint(n), d = 1;
    while(d == 1){
        x = (mul(x, x, n) + c) % n;
        y = (mul(y, y, n) + c) % n;
        y = (mul(y, y, n) + c) % n;
        d = gcd(abs(x - y), n);
    }
    pollard_rho(d);
    pollard_rho(n / d);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N; cin >> N;
    pollard_rho(N);
    sort(factors.begin(), factors.end());
    for(ll f : factors) cout << f << '\n';
}
