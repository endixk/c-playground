// BOJ 1040 [Integer]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

string N;
int K, L;
string build(const string& s, int mask, int cnt, bool flag) {
    if(!flag && !s.empty() && s[s.size()-1] < N[s.size()-1]) return "";
    if(L - s.size() < K - cnt) return "";
    if((int)s.size() == L) return cnt == K ? s : "";
    flag |= s[s.size()-1] > N[s.size()-1];
    for(int i=0; i<10; i++){
        if(mask & (1<<i)){
            string ret = build(s + to_string(i), mask, cnt, flag);
            if(!ret.empty()) return ret;
        }
        else if(cnt < K){
            string ret = build(s + to_string(i), mask | (1<<i), cnt+1, flag);
            if(!ret.empty()) return ret;
        }
    }
    return "";
}

inline int mask(const string& s){
    int ret = 0;
    for(char c : s) ret |= (1<<(c-'0'));
    return ret;
}
inline int cnt(const string& s){
    bool chk[10]; int ret = 0;
    memset(chk, 0, sizeof(chk));
    for(char c : s) {
        if(!chk[c-'0']) ret++;
        chk[c-'0'] = true;
    }
    return ret;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K; L = (int)N.size();

    string ret;
    for(int i=L; ret.empty() && i>=0; i--) ret = build(N.substr(0, i), mask(N.substr(0, i)), cnt(N.substr(0, i)), false);
    while(ret.empty()) L++, ret = build("1", 2, 1, true);
    cout << ret;
}