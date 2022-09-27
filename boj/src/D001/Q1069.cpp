// BOJ 1069 [Heading Home]
// Supported by GitHub Copilot

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, D, T; cin >> X >> Y >> D >> T;
    int dsq = X*X + Y*Y;

    // case 1. just walk
    double ans = sqrt(dsq);

    // case 2. home is closer than jump distance
    if (dsq <= D*D) {
        // case 2-1. jump and walk
        ans = min(ans, (double)T + D - sqrt(dsq));
        // case 2-2. jump twice
        ans = min(ans, (double)T * 2);
    }
    else { // case 3. home is farther than jump distance
        // count available jumps
        int cnt;
        for(cnt = 1; (cnt * D) * (cnt * D) <= dsq; cnt++);
        cnt--;

        // case 3-1. jump and walk
        ans = min(ans, (double)T * cnt + sqrt(dsq) - cnt * D);
        // case 3-2. jump and jump
        ans = min(ans, (double)T * (cnt + 1));
    }

    cout.precision(20);
    cout << ans;
}
