// BOJ 1150 [Backup]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define INF 1111111111

int loc[100005];
struct Interval {
    int s, e, d;
    Interval(int s, int e, int d) : s(s), e(e), d(d) {}
    bool operator<(const Interval& rhs) const {
        return d > rhs.d;
    }
};

priority_queue<Interval> pq;
bool visited[100005];
int pre[100005], nxt[100005], dst[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> loc[i];
    loc[0] = loc[1] - INF, loc[n+1] = loc[n] + INF; // padding
    for(int i=0; i<n+1; i++) {
        pre[i+1] = i, nxt[i] = i+1, dst[i] = loc[i+1] - loc[i];
        pq.push(Interval(i, i+1, dst[i]));
    }

    int ans = 0;
    while(k--){
        Interval best = pq.top();
        while(visited[best.s] || visited[best.e]) {
            pq.pop();
            best = pq.top();
        }
        pq.pop();
        ans += best.d;
        visited[best.s] = true; visited[best.e] = true;
        dst[pre[best.s]] = dst[pre[best.s]] + dst[best.e] - best.d;
        pre[nxt[best.e]] = pre[best.s];
        nxt[pre[best.s]] = nxt[best.e];
        pq.push(Interval(pre[best.s], nxt[best.e], dst[pre[best.s]]));
    }

    cout << ans;
    return 0;
}
