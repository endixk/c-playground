// BOJ 1213 [Palindrome Generation]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int cnt[26], odd = -1;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    for(char c : s) cnt[c-'A']++;

    for(int i=0; i<26; ++i){
        if(cnt[i] % 2){
            if(odd >= 0) return cout << "I'm Sorry Hansoo", 0;
            odd = i;
        }
    }

    for(int i=0; i<26; i++) for(int j=0; j<cnt[i]/2; j++) cout << (char)(i+'A');
    if(odd >= 0) cout << (char)(odd+'A');
    for(int i=25; i>=0; i--) for(int j=0; j<cnt[i]/2; j++) cout << (char)(i+'A');
}
