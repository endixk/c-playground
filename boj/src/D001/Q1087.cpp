// BOJ 1087 [Catch the Mice]
// Supported by GitHub Copilot

#include <iostream>
#include <cmath>
using namespace std;

int N, X[50], Y[50], VX[50], VY[50];
double maxDist(double t){
    double ret = 0;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            double cxi = X[i] + VX[i] * t,
                cyi = Y[i] + VY[i] * t,
                cxj = X[j] + VX[j] * t,
                cyj = Y[j] + VY[j] * t;
            double dist = max(abs(cxi - cxj), abs(cyi - cyj));
            if(dist > ret) ret = dist;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> VX[i] >> VY[i];

    // ternary search
    double lo = 0, hi = 3000;
    for(int i = 0; i < 1000; i++){
        double m1 = (2 * lo + hi) / 3,
               m2 = (lo + 2 * hi) / 3;
        if(maxDist(m1) > maxDist(m2)) lo = m1;
        else hi = m2;
    }

    cout.precision(15);
    cout << maxDist(lo) << endl;
}
