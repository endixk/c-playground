// BOJ 1173 [Excercise]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, m, M, T, R; cin >> N >> m >> M >> T >> R;

    if(m + T > M) return cout << -1, 0;
    int t = 0, c = 0, p = m;
    while(c < N){
        if(p + T <= M) p += T, c++;
        else p = max(p - R, m);
        t++;
    }
    cout << t;
}
