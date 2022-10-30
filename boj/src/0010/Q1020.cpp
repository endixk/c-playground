// BOJ 1020 [Digital Counter]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int seg[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
int dp[16][120][2];
string S; int L, K;
int solve(int p, int s, bool f, const string& debug){
    if(p == L) return (f && s == K) ? 0 : 10;
    int &ret = dp[p][s][f];
    if(ret != -1) return ret;

    ret = 10;
    for(int i=0; i<10; i++){
        if(!f && i < S[p] - '0') continue;
        if(solve(p+1, s + seg[i], f || (i > S[p] - '0'), debug + to_string(i)) < 10){
            ret = i;
            break;
        }
    }
    return ret;
}

string find(int p, int s, bool f){
    if(p == L) return "";
    return to_string(dp[p][s][f]) + find(p+1, s + seg[dp[p][s][f]], f || (dp[p][s][f] > S[p] - '0'));
}

ll ston(const string& s){
    ll ret = 0;
    for(char c : s){
        ret = ret * 10 + c - '0';
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> S; L = (int) S.size();
    for(int i=0; i<L; i++) K += seg[S[i] - '0'];
    ll si = ston(S), sj = 0;

    memset(dp, -1, sizeof(dp));
    solve(0, 0, false, "");

    if(dp[0][0][0] == 10){
        S = string(L, '0');
        memset(dp, -1, sizeof(dp));
        solve(0, 0, false, "");
        sj = ston("1"+S);
    }
    cout << sj + ston(find(0, 0, false)) - si;
}
