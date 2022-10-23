// BOJ 1193 [Find the Fraction]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int X, d; cin >> X;
    for(d=2; d*(d-1)/2 < X; d++);
    if(d%2) cout << X-(d-1)*(d-2)/2 << '/' << d-(X-(d-1)*(d-2)/2);
    else cout << d-(X-(d-1)*(d-2)/2) << '/' << X-(d-1)*(d-2)/2;
}
