// BOJ 1188 [Food Critics]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M; cin >> N >> M;
    cout << M - gcd(N, M);
}
