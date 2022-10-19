// BOJ 1181 [Sorting Words]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct comp {
    bool operator()(const string &a, const string &b) const {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }
};

set<string, comp> st;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    while(N--){
        string s; cin >> s;
        st.insert(s);
    }
    for (auto &s : st) cout << s << '\n';
}
