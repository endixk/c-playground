// BOJ 1205 [Ranking]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, S, P, s, r=0; cin >> N >> S >> P;
    for(int i=1; i<=N; ++i){
        cin >> s;
        if(S >= s && r == 0) r = i;
    }
    if(S == s && N == P) cout << -1;
    else if(r > 0) cout << r;
    else cout << (N < P ? N+1 : -1);
}
