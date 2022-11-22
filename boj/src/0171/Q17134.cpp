// BOJ 17134 [Lemoine's Conjecture]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

const double pi = acos(-1);
void fft(vector<complex<double>> &v, complex<double> w){
    int n = (int)v.size();
    if(n == 1) return;

    vector<complex<double>> e(n>>1), o(n>>1);
    for(int i = 0; i < n; i++){
        if(~i&1) e[i>>1] = v[i];
        else o[i>>1] = v[i];
    }

    fft(e, w*w);
    fft(o, w*w);

    complex<double> p(1, 0);
    for(int i = 0; i < (n>>1); i++){
        v[i] = e[i] + p * o[i];
        v[i+(n>>1)] = e[i] - p * o[i];
        p *= w;
    }
}

vector<complex<double>> multiply(vector<complex<double>> &a, vector<complex<double>> &b){
    int n = 1;
    while(n < (int)(a.size() + b.size())) n <<= 1;
    a.resize(n);
    b.resize(n);

    complex<double> w(cos(2*pi/n), sin(2*pi/n));
    fft(a, w);
    fft(b, w);

    for(int i = 0; i < n; i++) a[i] *= b[i];
    fft(a, complex<double>(1, 0) / w);

    for(int i = 0; i < n; i++) a[i] /= n;
    return a;
}

bool prime[MAX];
vector<complex<double>> pr(MAX, 0), sp(MAX, 0);
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // sieve
    fill(prime, prime + MAX, true);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<MAX; i++) {
        if(!prime[i]) continue;
        for(int j=i*i; j<MAX; j+=i) prime[j] = false;
    }

    // build vectors
    for(int i=0; i<MAX; i++){
        if(prime[i]){
            pr[i] = 1;
            if(i*2 < MAX && prime[i]) sp[i*2] = 1;
        }
    }
    pr[2] = 0;
    auto res = multiply(pr, sp);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        cout << (int)round(res[N].real()) << '\n';
    }
}
