// BOJ 1104 [Pattern]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll min(ll x, ll y){
    return x < y ? x : y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2; cin >> s1 >> s2;
    ll C; cin >> C;

    bool z1 = true, z2 = true;
    for(char c : s1) if(c != '0') z1 = false;
    for(char c : s2) if(c != '0') z2 = false;
    int L1 = s1.length(), L2 = s2.length();
    int l1, r1, l2, r2;
    if(!z1) {
        l1 = s1.find_first_not_of('0');
        r1 = s1.length() - s1.find_last_not_of('0') - 1;
    }
    else l1 = r1 = s1.length();
    if(!z2) {
        l2 = s2.find_first_not_of('0');
        r2 = s2.length() - s2.find_last_not_of('0') - 1;
    }
    else l2 = r2 = s2.length();

    ll loc = 1e17;
    // in S1
    if(C <= L1){
        for(int i = 0; i < L1 - C; i++){
            bool flag = true;
            for(int j = 0; j < C; j++){
                if(s1[i+j] != '0'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                loc = min(loc, (ll)i);
                break;
            }
        }
    }
    // in S1S1
    if(C <= r1 + l1) loc = min(loc, L1 - r1);
    // in S1S2
    if(C <= r1 + l2) loc = min(loc, 1000000 * L1 - r1);
    // in S2
    if(C <= L2){
        for(int i = 0; i < L2 - C; i++){
            bool flag = true;
            for(int j = 0; j < C; j++){
                if(s2[i+j] != '0'){
                    flag = false;
                    break;
                }
            }
            if(flag) {
                loc = min(loc, 1000000 * L1 + i);
                break;
            }
        }
    }
    // in S2S1
    if(C <= r2 + l1) loc = min(loc, 1000000 * L1 + L2 - r2);
    // in S2S2
    if(C <= r2 + l2) loc = min(loc, 2000000 * L1 + 2 * L2 - r2);

    if(z1 && !z2){ // if first string is zeros
        if(C <= 1000000 * L1 + l2) loc = 0;
        else if(C <= 1000000 * L1 + l2 + r2) loc = min(loc, 1000000 * L1 + L2 - r2);
    }
    else if(!z1 && z2){ // if second string is zeros
        ll n = (C - l1 - r1) / L2 + ((C - l1 - r1) % L2 != 0);
        if(n > 0 && n < (ll)1e9)
            if((ll)1e16 - (n*(n-1)/2 * L2 + 1000000 * n * L1 - r1) > C)
                loc = min(loc, n*(n-1)/2 * L2 + 1000000 * n * L1 - r1);
    }
    else if(z1 && z2) loc = 0;
    if(loc >= (ll)1e16) cout << -1;
    else cout << loc;
}
