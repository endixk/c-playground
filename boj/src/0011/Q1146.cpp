// BOJ 1146 [Zigzag Order]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000

int E[101][101];
int entringer(int n, int k){
    if(n == 0 && k == 0) return 1;
    if(k == 0) return 0;
    if(E[n][k] != -1) return E[n][k];
    return E[n][k] = (entringer(n, k-1) + entringer(n-1, n-k)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    if(N == 1) return cout << 1, 0;
    memset(E, -1, sizeof(E));
    cout << entringer(N, N) * 2 % MOD;
}
