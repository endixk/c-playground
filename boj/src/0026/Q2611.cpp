// BOJ 2611 [Car Race]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<pair<int,int>> adj_fw[MAX], adj_bw[MAX];
int ind_fw[MAX], ind_bw[MAX], trk_fw[MAX], trk_bw[MAX], max_fw[MAX], max_bw[MAX];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;

    for (int i=0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj_fw[u].emplace_back(v, w); ind_fw[v]++;
        adj_bw[v].emplace_back(u, w); ind_bw[u]++;
    }

    // forward
    queue<int> q;
    q.emplace(1); ind_fw[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &[v, w] : adj_fw[u]) {
            if (ind_fw[v] == 0) continue;
            if (max_fw[v] < max_fw[u] + w) {
                max_fw[v] = max_fw[u] + w;
                trk_fw[v] = u;
            }
            if (--ind_fw[v] == 0) q.emplace(v);
        }
    }

    // backward
    q.emplace(1); ind_bw[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &[v, w] : adj_bw[u]) {
            if (ind_bw[v] == 0) continue;
            if (max_bw[v] < max_bw[u] + w) {
                max_bw[v] = max_bw[u] + w;
                trk_bw[v] = u;
            }
            if (--ind_bw[v] == 0) q.emplace(v);
        }
    }

    int ans = 0, loc = 1;
    for (int i=2; i<=n; i++) {
        if (ans < max_fw[i] + max_bw[i]) {
            ans = max_fw[i] + max_bw[i];
            loc = i;
        }
    }

    deque<int> path; int lcp = loc;
    while (lcp != 1) {
        lcp = trk_fw[lcp];
        path.emplace_front(lcp);
    }
    while (loc != 1) {
        path.emplace_back(loc);
        loc = trk_bw[loc];
    }
    cout << ans << '\n';
    for (auto &i : path) cout << i << ' ';
    cout << "1\n";
}