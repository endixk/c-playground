// BOJ Contest 895-B
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

map<string,int> m; int c;
bool d[2001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    while(N--){
        string s, t; cin >> s >> t;
        if(m.find(s) == m.end()) m[s] = c++;
        if(m.find(t) == m.end()) m[t] = c++;
        if(s == "ChongChong") d[m[s]] = true;
        if(t == "ChongChong") d[m[t]] = true;
        if(d[m[s]] && !d[m[t]]) d[m[t]] = true;
        if(!d[m[s]] && d[m[t]]) d[m[s]] = true;
    }

    int ans = 0;
    for(bool x : d) ans += x;
    cout << ans;
}