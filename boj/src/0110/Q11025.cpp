// BOJ 11025 [Josephus Problem 3]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k; cin >> n >> k;
    int ret = 1;
    for(int i = 2; i <= n; i++) ret = (ret + k - 1) % i + 1;
    cout << ret;
}
