// BOJ 1182 [Subset Sum]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N, S, V[20];
int track(int x, int s){
    if(x == N) return s == S;
    return track(x+1, s+V[x]) + track(x+1, s);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> V[i];
    cout << track(0, 0) - (S == 0);
}
