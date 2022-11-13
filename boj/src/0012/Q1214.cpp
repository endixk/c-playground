// BOJ 1214 [Purchasing a Product]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

inline int d(int a, int b){
    if(a < 0) return 0;
    return a / b + (a % b != 0);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int D, P, Q; cin >> D >> P >> Q;
    if(P < Q) swap(P, Q);

    int ans = D+P;
    for(int i = 0; i <= min(d(D,P), Q); i++)
        ans = min(ans, i*P + d(D-i*P,Q)*Q);
    cout << ans;
}
