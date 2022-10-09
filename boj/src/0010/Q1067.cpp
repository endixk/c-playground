// BOJ 1067 [Movement]
// Supported by GitHub Copilot

#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
using namespace std;

const double pi = acos(-1);
void fft(vector<complex<double>> &v, complex<double> w){
    int n = v.size();
    if(n == 1) return;

    vector<complex<double>> e(n/2), o(n/2);
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) e[i/2] = v[i];
        else o[i/2] = v[i];
    }

    fft(e, w*w);
    fft(o, w*w);

    complex<double> p(1, 0);
    for(int i = 0; i < n/2; i++){
        v[i] = e[i] + p * o[i];
        v[i+n/2] = e[i] - p * o[i];
        p *= w;
    }
}

vector<complex<double>> multiply(vector<complex<double>> &a, vector<complex<double>> &b){
    int n = 1;
    while(n < a.size() + b.size()) n *= 2;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<complex<double>> X(2*N), Y(N);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        X[i] = X[N+i] = complex((double) x, .0);
    }
    for(int i = 0; i < N; i++) {
        int y;
        cin >> y;
        Y[N - i - 1] = complex((double) y, .0);
    }

    vector<complex<double>> Z = multiply(X, Y);
    int ans = 0;
    for(int i = N-1; i < 2*N-1; i++) ans = max(ans, (int) round(Z[i].real()));
    cout << ans << '\n';
}
