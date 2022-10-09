// BOJ 1093 [Purchasing Stickers]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> A[1<<16], B[1<<16]; // {value, price}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int V[N], P[N]; // value and price
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> V[i];
    int K; cin >> K;
    int M; cin >> M;
    int S[M];
    for (int i = 0; i < M; i++) cin >> S[i];

    // compute subsets from the first half to A
    for (int i = 0; i < N/2; i++){
        int n = 1 << i;
        for (int j = 0; j < (1 << (N/2)); j++) {
            if(j & n) {
                A[j].first += V[i];
                A[j].second += P[i];
            }
        }
    }
    // compute subsets from the second half to B
    for (int i = N/2; i < N; i++){
        int n = 1 << (i - N/2);
        for (int j = 0; j < (1 << (N - N/2)); j++) {
            if(j & n) {
                B[j].first += V[i];
                B[j].second += P[i];
            }
        }
    }

    // sort B by value and adjust price
    sort(B, B + (1 << (N - N/2)));
    for (int i = (1 << (N - N/2)) - 2; i >= 0; i--) {
        B[i].second = min(B[i].second, B[i+1].second);
    }

    // find the best price
    int ans = INT32_MAX;
    for (int i = 0; i < (1 << (N/2)); i++) {
        pair<int,int> p = {K - A[i].first, 0};
        int j = lower_bound(B, B + (1 << (N - N/2)), p) - B;
        if(j >= (1 << (N - N/2))) continue;
        if(B[j].first + A[i].first >= K) ans = min(ans, A[i].second + B[j].second);
    }
    if(ans == INT32_MAX) {
        cout << -1;
        return 0;
    }

    // subtract the price of stickers in possession
    int h = 0;
    for (int i = 0; i < M; i++) h += P[S[i]];
    cout << max(0, ans - h);
}
