// BOJ 1225 [Peculiar Multiplication]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string A, B; cin >> A >> B;
    ll a = 0, b = 0;
    for (char c : A) a += c - '0';
    for (char c : B) b += c - '0';
    cout << a * b;
}
