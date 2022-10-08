// BOJ 2042 [Interval Sum]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[1<<20], seg[1<<21];

// build segment tree
ll build(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];
    int m = (s+e)/2;
    return seg[node] = build(node*2, s, m) + build(node*2+1, m+1, e);
}

// update segment tree (arr[idx] = val)
ll update(int node, int s, int e, int idx, ll val) {
    if (idx < s || e < idx) return seg[node];
    if (s == e) return seg[node] = val;
    int m = (s+e)/2;
    return seg[node] = update(node*2, s, m, idx, val) + update(node*2+1, m+1, e, idx, val);
}

// query segment tree (arr[s] + arr[s+1] + ... + arr[e])
ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int m = (s+e)/2;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    build(1, 0, N-1);
    for (int i = 0; i < M+K; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        if (a == 1) update(1, 0, N - 1, b - 1, c);
        else cout << query(1, 0, N - 1, b - 1, (int) c - 1) << '\n';
    }
}
