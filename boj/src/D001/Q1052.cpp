// BOJ 1052 [Water bottle]
// Supported by GitHub Copilot

#include <iostream>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;

    int val = N;
    while((bitset<32>(val++).count()) > K);
    cout << --val - N << '\n';
}
