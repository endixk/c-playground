// BOJ 1065 [Hansu]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

bool isHansu(int n){
    if (n < 100) return true;
    if (n == 1000) return false;
    int a = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int c = n % 10;
    return (a - b) == (b - c);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) if (isHansu(i)) cnt++;
    cout << cnt << '\n';
}
