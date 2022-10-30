// BOJ 1201 [NMK]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N, M, K, x, g;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;

    if(N < M+K-1 || N > M*K) return cout << -1, 0;
    for(int i=1; i<=N; i++){
        if(i-x == K || N-i+1 == M-g){
            for(int j=i; j>x; j--) cout << j << ' ';
            x=i, g++;
        }
    }
}
