// BOJ 13261 [Jailbreak]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 8002
#define INF 0x3f3f3f3f3f3f3f3f

int L, G;
ll C[MAX], S[MAX], D[MAX], T[MAX];
void dnc(int s, int e, int l, int r){
    if(s > e) return;
    int m = (s+e)>>1, n = -1;
    D[m] = INF;
    for(int i=l; i<=r && i<=m; i++){
        ll v = T[i] + (S[m] - S[i]) * (m - i);
        if(D[m] > v){
            D[m] = v;
            n = i;
        }
    }
    dnc(s, m-1, l, n);
    dnc(m+1, e, n, r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> L >> G;
    for(int i=1; i<=L; i++) cin >> C[i], S[i] = S[i-1] + C[i];
    for(int i=1; i<=L; i++) T[i] = S[i] * i;
    for(int i=2; i<=G; i++) {
        dnc(0, L, 0, L);
        for(int j=0; j<=L; j++) T[j] = D[j];
    }
    cout << D[L];
}
