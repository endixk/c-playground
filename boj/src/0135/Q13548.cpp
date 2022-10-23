// BOJ 13548 [Sequence and Queries 6]
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
int cmx, carr[NMAX], ccarr[NMAX], ans[SMAX];
inline void add(int x){
    ccarr[carr[x]]--;
    carr[x]++;
    ccarr[carr[x]]++;
    cmx = max(cmx, carr[x]);
}
inline void sub(int x){
    ccarr[carr[x]]--;
    carr[x]--;
    ccarr[carr[x]]++;
}
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
    ccarr[0] = N;
    int l = queries[0].l, r = queries[0].r;
    for(int i=l; i<=r; i++) add(arr[i]);
    ans[queries[0].i] = cmx;
    for(int i=1; i<M; i++){
        process(l, queries[i].l, r, queries[i].r);
        while(ccarr[cmx] == 0) cmx--;
        ans[queries[i].i] = cmx;
        l = queries[i].l, r = queries[i].r;
    }
    for(int i=0; i<M; i++) cout << ans[i] << '\n';
}
