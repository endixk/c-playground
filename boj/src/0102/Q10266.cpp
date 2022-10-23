// BOJ 10266 [Pictures of Clocks]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SIZE 360000

// KMP - get pi table
vector<int> getPi(string p) {
    int m = (int)p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

// KMP
bool kmp(string s, string p) {
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) return true;
            else j++;
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s(SIZE, '0'), t(SIZE, '0');
    for(int i=0; i<n; i++){
        int x; cin >> x;
        s[x] = '1';
    }
    for(int i=0; i<n; i++){
        int x; cin >> x;
        t[x] = '1';
    }
    cout << (kmp(s+s, t) ? "possible" : "impossible");
}
