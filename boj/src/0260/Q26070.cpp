// BOJ Contest 895-C
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int X, Y, Z, A, B, C;
    cin >> A >> B >> C >> X >> Y >> Z;

    long long ans = 0;
    int t;
    while(X >= 3 || Y >= 3 || Z >= 3) {
        t = min(X, A);
        ans += t, X -= t, A -= t;
        if (X > 0) Y += X / 3, X %= 3;
        t = min(Y, B);
        ans += t, Y -= t, B -= t;
        if (Y > 0) Z += Y / 3, Y %= 3;
        t = min(Z, C);
        ans += t, Z -= t, C -= t;
        if (Z > 0) X += Z / 3, Z %= 3;
        if(A + B + C == 0) break;
    }
    ans += min(X, A) + min(Y, B) + min(Z, C);
    cout << ans;
}