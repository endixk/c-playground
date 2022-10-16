// BOJ 1157 [Study Words]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;
    map<int,int> m;
    for(char c : s) m[toupper(c)]++;
    int mx = 0; char ans = '?';
    for(auto [k,v] : m) {
        if(mx < v) mx = v, ans = (char)k;
        else if(mx == v) ans = '?';
    }
    cout << ans;
}
