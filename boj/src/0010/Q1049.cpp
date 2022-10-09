// BOJ 1049 [Guitar strings]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int p = 1000, q = 1000;
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        p = min(p, a);
        q = min(q, b);
    }

    cout << min(min(p*(N/6) + q*(N%6), p*((N+5)/6)), q*N) << '\n';
}