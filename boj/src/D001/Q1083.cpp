// BOJ 1083 [Sort]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    int S; cin >> S;

    int sarr[N];
    for (int i = 0; i < N; i++) sarr[i] = arr[i];
    sort(sarr, sarr+N, greater<>());

    for(int i = 0; i < N; i++) {
        if (S == 0) break;
        int mx = arr[i], mi = i;
        for(int j = i+1; j <= i+S && j < N; j++){
            if (mx < arr[j]) {
                mx = arr[j];
                mi = j;
            }
        }
        for(int j = mi; j > i; j--) {
            swap(arr[j], arr[j-1]);
            S--;
        }
    }

    for (int i = 0; i < N; i++) cout << arr[i] << ' ';
}
