// BOJ 1159 [Basketball]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    int cnt[26]; memset(cnt, 0, sizeof(cnt));
    while (N--) {
        string s; cin >> s;
        cnt[s[0] - 'a']++;
    }

    vector<char> ans;
    for(int i=0; i<26; i++) {
        if (cnt[i] >= 5) ans.push_back((char)('a'+i));
    }
    if(ans.empty()) cout << "PREDAJA";
    else for(char c : ans) cout << c;

}
