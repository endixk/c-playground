// BOJ 1212 [Oct to Bin]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr)->sync_with_stdio(false);

    string s, t; cin >> s;
    string conv[] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    int x = s[0] - '0';
    if(x == 0) t = "0";
    else if(x == 1) t = "1";
    else if(x < 4) t += conv[x].substr(1);
    else t += conv[x];

    for(char c : s.substr(1)) t += conv[c - '0'];
    cout << t;
}
