// BOJ 1786 [Search]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

// KMP - get pi table
vector<int> getPi(string p) {
    int m = p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

// KMP
vector<int> kmp(string s, string p) {
    vector<int> ans;
    auto pi = getPi(p);
    int n = s.size(), m = p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else j++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string T, P;
    getline(cin, T);
    getline(cin, P);
    vector<int> ans = kmp(T, P);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i+1 << ' ';
}
