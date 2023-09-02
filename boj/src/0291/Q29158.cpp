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

vector<ll> A, B;
bool cmp(ll a, ll b) {
    int al = (ll)log10(a) + 1, bl = (ll)log10(b) + 1;
    return a * power(10, bl, 1e18) + b < b * power(10, al, 1e18) + a;
}
void debug() {
    for(ll i : factors) cout << i << " ";
    cout << "\n";
    for(int i=(int)A.size()-1; i>=0; i--) cout << A[i];
    cout << "\n";
    for(int i=(int)B.size()-1; i>=0; i--) cout << B[i];
    cout << "\n";
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N; cin >> N;
    pollard_rho(N);
    sort(factors.begin(), factors.end(), cmp);
    for(ll f : factors) {
        while(f) {
            A.emplace_back(f % 10);
            f /= 10;
        }
    }
    --N;
    while(N > 3) {
        B.emplace_back(2);
        N /= 2;
    }
    B.emplace_back(N);

    //debug();

    while(A.size() < B.size()) A.emplace_back(0);

    vector<int> S;
    int s = (int)A.size() - 1;
    for(int i=0; i<s; i++) {
        S.emplace_back((A[i] + B[i]) % 10);
        if(A[i] + B[i] >= 10) A[i+1]++;
    }
    S.emplace_back((A[s] + B[s]) % 10);
    if(A[s] + B[s] >= 10) S.emplace_back(1);

    reverse(S.begin(), S.end());
    for(int i : S) cout << i;
}
