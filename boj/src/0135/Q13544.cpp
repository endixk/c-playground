// BOJ 13544 [Sequence and Queries 2]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

vector<int> seg[1<<18];
vector<int> merge(const vector<int> &a, const vector<int> &b) {
    vector<int> ret;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) ret.push_back(a[i++]);
        else ret.push_back(b[j++]);
    }
    while (i < a.size()) ret.push_back(a[i++]);
    while (j < b.size()) ret.push_back(b[j++]);
    return ret;
}

vector<int> arr;
vector<int> build(int node, int s, int e) {
    if (s == e) return seg[node] = {arr[s]};
    int m = (s+e)/2;
    return seg[node] = merge(build(node*2, s, m), build(node*2+1, m+1, e));
}
int query(int node, int s, int e, int l, int r, int val){
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), val);
    int m = (s+e)/2;
    return query(node*2, s, m, l, r, val) + query(node*2+1, m+1, e, l, r, val);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M; cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    build(1, 0, N-1);
    cin >> M;
    int a, b, c, last = 0;
    while (M--) {
        cin >> a >> b >> c;
        last = query(1, 0, N-1, (a^last)-1, (b^last)-1, c^last);
        cout << last << '\n';
    }
}
