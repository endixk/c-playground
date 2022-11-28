// BOJ Contest 895-E
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N, L;
int X[MAX], W[MAX];
double diff(double loc){
    double ret = 0;
    for(int i=0; i<N; i++) ret += W[i] * (X[i] - loc);
    return abs(ret);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> L;
    for(int i=0; i<N; i++) cin >> X[i];
    for(int i=0; i<N; i++) cin >> W[i];

    // ternary search
    double lo = 0, hi = L;
    for(int i=0; i<100; i++){
        double mid1 = diff((lo*2 + hi) / 3);
        double mid2 = diff((lo + hi*2) / 3);
        if(mid1 < mid2) hi = (lo + hi*2) / 3;
        else lo = (lo*2 + hi) / 3;
    }
    cout << fixed << setprecision(10) << lo;
}