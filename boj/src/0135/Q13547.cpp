// BOJ 13547 [Sequence and Queries 5]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SMAX 100001
#define NMAX 1000001

int N, M, arr[SMAX];
struct Query {
    int l, r, i;
    Query(int l, int r, int i): l(l), r(r), i(i) {}
    bool operator<(const Query &rhs) const {
        int ll = l / (int)sqrt(N), lr = rhs.l / (int)sqrt(N);
        if(ll == lr) return r < rhs.r;
        return ll < lr;
    }
};
vector<Query> queries;
int cnt = 0, carr[NMAX], ans[SMAX];
inline void add(int x){if(carr[x]++ == 0) cnt++;}
inline void sub(int x){if(--carr[x] == 0) cnt--;}
void process(int l1, int l2, int r1, int r2){
    while(l1 > l2) add(arr[--l1]);
    while(r1 < r2) add(arr[++r1]);
    while(l1 < l2) sub(arr[l1++]);
    while(r1 > r2) sub(arr[r1--]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    cin >> M;
    for(int i=0; i<M; i++){
        int l, r; cin >> l >> r;
        queries.emplace_back(l, r, i);
    }
    sort(queries.begin(), queries.end());
    int l = queries[0].l, r = queries[0].r;
    for(int i=l; i<=r; i++) add(arr[i]);
    ans[queries[0].i] = cnt;
    for(int i=1; i<M; i++){
        process(l, queries[i].l, r, queries[i].r);
        l = queries[i].l, r = queries[i].r;
        ans[queries[i].i] = cnt;
    }
    for(int i=0; i<M; i++) cout << ans[i] << '\n';
}
