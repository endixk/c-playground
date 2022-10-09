// BOJ 1057 [Tournament]
// Supported by GitHub Copilot

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, x, y; cin >> N >> x >> y;

    int r = 0, n = 1;
    while(n < N){
        n *= 2;
        r++;
    }

    x--; y--;
    while(n > 1){
        n /= 2;
        if(x/n != y/n) break;
        r--;
    }
    cout << r << '\n';
}