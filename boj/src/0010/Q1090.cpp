// BOJ 1090 [Checkers]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int X[N], Y[N];
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    int ans[N+1];
    fill(ans, ans+N+1, INT32_MAX);
    ans[0] = 0;

    // for each possible median points
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x = X[i], y = Y[j];

            // calculate manhattan distances
            int dist[N];
            for (int k = 0; k < N; k++) dist[k] = abs(X[k] - x) + abs(Y[k] - y);

            // sort and accumulate
            sort(dist, dist + N);
            int acc = 0;
            for (int k = 0; k < N; k++) {
                acc += dist[k];
                ans[k + 1] = min(ans[k + 1], acc);
            }
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
}
