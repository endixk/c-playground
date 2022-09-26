// BOJ 1059 [Good Interval]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L; cin >> L;
    int arr[L];
    for (int i = 0; i < L; i++) cin >> arr[i];
    sort(arr, arr + L);

    int S; cin >> S;
    int x = 0, y = 0;
    for(int i = 0; arr[i] <= S; i++) x = arr[i];
    for(int i = L - 1; arr[i] >= S; i--) y = arr[i];

    if(x == 0) cout << (arr[0] - S) * S - 1 << '\n';
    else if(x == y) cout << 0 << '\n';
    else cout << (y - S) * (S - x) - 1 << '\n';
}
