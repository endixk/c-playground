// BOJ 13576 [Prefix and Suffix]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

vector<int> Z, T;
void calcZ(const string &s){
    int n = (int)s.size();
    Z[0] = n;
    for(int i=1, l=0, r=0; i<n; i++){
        if(i <= r) Z[i] = min(r-i+1, Z[i-l]);
        while(i+Z[i] < n && s[Z[i]] == s[i+Z[i]]) Z[i]++;
        if(i+Z[i]-1 > r) l = i, r = i+Z[i]-1;
    }
}

vector<pair<int,int>> ans;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = (int)s.size();
    Z.resize(n), T.resize(n);

    calcZ(s); T = Z;
    sort(T.begin(), T.end());

    for(int i=n-1; i>=0; i--){
        if(Z[i] == n-i) ans.emplace_back(Z[i], T.end() - lower_bound(T.begin(), T.end(), Z[i]));
    }

    cout << ans.size() << '\n';
    for(auto [a, b] : ans) cout << a << ' ' << b << '\n';
}
