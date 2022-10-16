// BOJ 1168 [Josephus Problem 2]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int alive[100001], seg[1<<18];

int build(int node, int s, int e) {
    if (s == e) return seg[node] = alive[s];
    int m = (s+e)/2;
    return seg[node] = build(node*2, s, m) + build(node*2+1, m+1, e);
}

int remove(int node, int s, int e, int idx) {
    if (idx < s || e < idx) return seg[node];
    if (s == e) return seg[node] = 0;
    int m = (s+e)/2;
    return seg[node] = remove(node*2, s, m, idx) + remove(node*2+1, m+1, e, idx);
}

int query(int node, int s, int e, int k) {
    if (s == e) return s;
    int m = (s+e)/2;
    if (k <= seg[node*2]) return query(node*2, s, m, k);
    return query(node*2+1, m+1, e, k-seg[node*2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++) alive[i] = 1;
    build(1, 1, N);

    int idx = K;
    cout << '<';
    for (int i = 0; i < N; i++) {
        int next = query(1, 1, N, idx);
        remove(1, 1, N, next);
        cout << next;
        if (i != N-1) cout << ", ";
        else break;
        idx = (idx+K-1) % (N-i-1);
        if (idx == 0) idx = N-i-1;
    }
    cout << '>';
}
