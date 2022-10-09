// BOJ 1088 [Cake]
// Supported by GitHub Copilot

#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<double, int>> PQ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    double size[N];
    double MIN = 1e9;
    for (int i = 0; i < N; i++) {
        double x; cin >> x;
        size[i] = x;
        PQ.emplace(x, i);
        MIN = min(MIN, x);
    }
    int M; cin >> M;

    int cuts[N];
    for (int i = 0; i < N; i++) cuts[i] = 1;
    double ans = PQ.top().first - MIN;
    for(int i = 0; i < M; i++) {
        int idx = PQ.top().second; PQ.pop();
        cuts[idx]++;
        PQ.emplace(size[idx] / cuts[idx], idx);
        MIN = min(MIN, size[idx] / cuts[idx]);
        ans = min(ans, PQ.top().first - MIN);
    }

    cout.precision(15);
    cout << ans;
}
