// BOJ 1074 [Z]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int z(int x, int y, int sz){
    if(sz == 1) return 0;

    int med = sz >> 1;
    if(x < med && y < med) return z(x, y, med);
    if(x >= med && y < med) return med * med + z(x - med, y, med);
    if(x < med && y >= med) return med * med * 2 + z(x, y - med, med);
    if(x >= med && y >= med) return med * med * 3 + z(x - med, y - med, med);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, r, c; cin >> N >> r >> c;
    cout << z(c, r, 1 << N);
}
