// BOJ 1546 [Average]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m=0, s=0; cin >> n;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        m = max(m, x);
        s += x;
    }
    cout << (double)s/m/n*100;
}
