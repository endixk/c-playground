// BOJ 11689 [GCD(n, k) = 1]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll phi(ll pri, ll pow){
    ll ret = 1;
    for(int i=0; i<pow; i++){
        ret *= pri;
    }
    return ret - ret/pri;
}

ll phi(ll x){
    ll ret = 1;
    for(ll pri = 2; pri*pri <= x; pri++){
        if(x%pri == 0){
            int pow = 0;
            while(x%pri == 0){
                x /= pri;
                pow++;
            }
            ret *= phi(pri, pow);
        }
    }
    if(x > 1) ret *= phi(x, 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll N; cin >> N;
    cout << phi(N);
}
