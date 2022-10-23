// BOJ 16978 [Sequence and Queries 22]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

int N, M;
ll arr[MAX], seg[1<<18];
ll build(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];
    int m = (s+e)/2;
    return seg[node] = build(node*2, s, m) + build(node*2+1, m+1, e);
}
ll update(int node, int s, int e, int idx, int val) {
    if (idx < s || e < idx) return seg[node];
    if (s == e) return seg[node] = val;
    int m = (s+e)/2;
    return seg[node] = update(node*2, s, m, idx, val) + update(node*2+1, m+1, e, idx, val);
}
ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int m = (s+e)/2;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

struct Query {
    int a, b, i;
    Query(int a, int b, int i): a(a), b(b), i(i) {}
    bool operator < (const Query &o) const {
        return a < o.a;
    }
};

vector<pair<int,int>> updates;
vector<pair<int,Query>> queries;
ll ans[MAX];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    build(1, 1, N);
    cin >> M;

    int qcnt = 0;
    for(int i=0; i<M; i++){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y;
            updates.emplace_back(x, y);
        }
        else{
            int x, y, k; cin >> k >> x >> y;
            queries.emplace_back(k, Query(x, y, qcnt++));
        }
    }

    sort(queries.begin(), queries.end());
    int last = 0;
    for(auto [k, qr] : queries){
        for(;last<k; last++){
            auto [x, y] = updates[last];
            update(1, 1, N, x, y);
        }
        auto [x, y, i] = qr;
        ans[i] = query(1, 1, N, x, y);
    }
    for(int i=0; i<qcnt; i++) cout << ans[i] << '\n';
}
