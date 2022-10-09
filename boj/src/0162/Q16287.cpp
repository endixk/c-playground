// BOJ 16287 [Parcel]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 400001

int arr[5001], x[MAX], y[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int W, N; cin >> W >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    fill(x, x+MAX, -1);
    fill(y, y+MAX, -1);

    // for every pair, store x, y by their sum
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            int s = arr[i] + arr[j];
            if(s >= MAX) continue;
            if(x[s] < 0) {
                x[s] = i;
                y[s] = j;
            }
        }
    }

    // find pair with sum w where non-overlapping pair with sum W-w exists
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            int s = arr[i] + arr[j];
            if(W-s >= MAX || W-s < 0) continue;
            if(x[W-s] >= 0 && x[W-s] != i && x[W-s] != j && y[W-s] != i && y[W-s] != j) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}
