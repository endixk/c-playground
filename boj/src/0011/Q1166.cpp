// BOJ 1166 [Gift]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    double N, L, W, H;
    cin >> N >> L >> W >> H;

    double lo = 0, hi = min({L, W, H});
    for(int i = 0; i < 1000; i++){
        double mid = (lo + hi) / 2;
        double cnt = floor(L / mid) * floor(W / mid) * floor(H / mid);
        if(cnt >= N) lo = mid;
        else hi = mid;
    }

    cout << setprecision(15) << lo;
}
