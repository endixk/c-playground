// BOJ 1195 [Kickdown]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

bool match(const string& a, const string& b) {
    for(int i=0; i<(int)a.size(); i++){
        if(a[i] == '2' && b[i] == '2') return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t; cin >> s >> t;
    if(s.size() > t.size()) swap(s, t);

    int ls = (int)s.size(), lt = (int)t.size();
    for(int i=0; i<=lt-ls; i++){ // overlap
        if(match(s, t.substr(i, ls))) return cout << lt, 0;
    }
    for(int i=1; i<=ls; i++){
        if(match(s.substr(i), t.substr(0, ls-i))) return cout << lt+i, 0;
        if(match(s.substr(0, ls-i), t.substr(lt-ls+i))) return cout << lt+i, 0;
    }
    cout << lt+ls;
}
