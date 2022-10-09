// BOJ 1094 [Cutting Sticks]
// Supported by GitHub Copilot

#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n; cin >> n;
    bitset<7> b(n);
    cout << b.count();
}
