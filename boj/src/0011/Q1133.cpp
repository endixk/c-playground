// BOJ 1133 [Non-repeating Word]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

// check if given string is repeating
bool rep(const string& s, int len){
    for(int i=0; i<s.length()-len; i+=len){
        if(s.substr(i, len) != s.substr(i+len, len)) return false;
    }
    return true;
}

int K, N, A;
string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void build(const string& s){
    if(s.length() == N) {
        cout << s;
        exit(0);
    }
    for(int i=0; i<A; i++){
        string t = s + alph[i];
        int len = (int)t.length(), j = 1;
        bool flag = true;
        while(len - j * K >= 0){
            if(rep(t.substr(len - j * K), j)) {
                flag = false;
                break;
            }
            j++;
        }
        if(flag) build(t);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> N >> A;
    build("");
    cout << -1;
}
