// BOJ 1222 [HJ Programming Contest]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXK 2000001

int N, K, ex[MAXK];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++) cin >> K, ex[K]++;

    ll ans = 0;
    for(int i=1; i<MAXK; i++){
        int cnt = 0;
        for(int j=i; j<MAXK; j+=i) cnt += ex[j];
        if(cnt > 1) ans = max(ans, (ll)i*cnt);
    }
    cout << ans;
}
