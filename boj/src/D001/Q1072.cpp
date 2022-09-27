// BOJ 1072 [Game]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    cin >> x >> y;
    long long z = y * 100 / x;

    if (z >= 99) cout << -1;
    else cout << (x * (z + 1) - 100 * y) / (99 - z) + ((x * (z + 1) - 100 * y) % (99 - z) == 0 ? 0 : 1);
}
