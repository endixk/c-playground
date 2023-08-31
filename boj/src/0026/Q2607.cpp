// BOJ 2607 [Similar Words]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

bool sim(vector<int> a, vector<int> b) {
    int ins = 0, del = 0;
    for (int i=0; i<26; ++i) {
        if (a[i] < b[i]) { ins += b[i] - a[i]; }
        else { del += a[i] - b[i]; }
    }
    return ins <= 1 && del <= 1;
}
inline vector<int> profile(string s) {
    vector<int> ret(26);
    for (char c : s) { ++ret[c - 'A']; }
    return ret;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p = profile(s);

    int ans = 0;
    for (int i=1; i<n; i++) {
        cin >> s;
        vector<int> q = profile(s);
        if (sim(p, q)) { ++ans; }
    }
    cout << ans;
}
