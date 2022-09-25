// BOJ 1053 [Palindrome factory]
// Supported by GitHub Copilot

#include <iostream>
#include <cstring>
using namespace std;

int dp[50][50];
int palin(string s, int l, int r){
    if(dp[l][r] >= 0) return dp[l][r];
    if(l >= r) return dp[l][r] = 0;

    return dp[l][r] = min(palin(s, l+1, r-1) + (s[l] == s[r] ? 0 : 1),
                          min(palin(s, l+1, r) + 1, palin(s, l, r-1) + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    int MIN = palin(s, 0, s.size() - 1);

    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            swap(s[i], s[j]);
            memset(dp, -1, sizeof(dp));
            MIN = min(MIN, palin(s, 0, s.size() - 1) + 1);
            swap(s[i], s[j]);
        }
    }

    cout << MIN << '\n';
}
