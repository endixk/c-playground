// BOJ 1196 [Jack Bauer]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_BRUTE 100000
#define MAX_TAYLOR 1000000000000
#define GAMMA 0.57721566490153286060651209008240243104215933593992

double brute(ll N, ll K){
    double ret = 0;
    for(ll i=N; i>N-K; i--){
        ret += (double)N/(double)i;
    }
    return ret;
}

double calc_taylor(ll N, ll K){
    double ret = 0, dn = (double)N, dk = (double)K;
    double pow = dn * dk / (dn - dk);
    for(ll i=1; i<MAX_BRUTE; i++){
        ret += (i % 2 ? 1.0 : -1.0) * pow / (double)i;
        pow *= dk / (dn - dk);
    }

    ret += 0.5 - 1.0 / 12 / dn;
    ret += dn / 12 / (dn - dk) / (dn - dk) - dn / 2 / (dn - dk);
    return ret;
}

// N/1 + N/2 + ... + N/x
double calc_brute(ll N, ll x);
double calc_apprx(ll N, ll x);
double calc(ll N, ll x){
    if(x < MAX_BRUTE) return calc_brute(N, x);
    return calc_apprx(N, x);
}

double calc_brute(ll N, ll x){
    double ret = 0;
    for(ll i=1; i<=x; i++){
        ret += (double)N/(double)i;
    }
    return ret;
}
double calc_apprx(ll N, ll x){
    double ret = 0, dn = (double)N, dx = (double)x;
    ret += dn * log1p(dx - 1);
    ret += dn * GAMMA;
    ret += dn / 2 / dx;
    ret -= dn / 12 / dx / dx;
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, K; cin >> N >> K;

    cout << fixed << setprecision(15);
    if(K < MAX_BRUTE) cout << brute(N, K);
    if(K < MAX_TAYLOR && K < N/10) cout << calc_taylor(N, K);
    else cout << calc(N, N) - calc(N, N-K);
}
