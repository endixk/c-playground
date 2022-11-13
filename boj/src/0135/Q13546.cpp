// BOJ 13546 [Sequence and Queries 4]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MSQ 300
#define MBK 350

int N, K, M;
struct Query {
    int l, r, i;
    Query(int l, int r, int i): l(l), r(r), i(i) {}
    bool operator<(const Query &rhs) const {
        int ll = l / MSQ, lr = rhs.l / MSQ;
        if(ll == lr) return r < rhs.r;
        return ll < lr;
    }
};

vector<Query> queries;
vector<deque<int>> dq(MAX);
int arr[MAX], cnt[MAX], bkt[MBK];

void add(int x, bool front){
    int v = arr[x];
    if(!dq[v].empty()){
        int d = dq[v].back() - dq[v].front();
        cnt[d]--, bkt[d/MSQ]--;
    }
    if(front) dq[v].push_front(x);
    else dq[v].push_back(x);
    int d = dq[v].back() - dq[v].front();
    cnt[d]++, bkt[d/MSQ]++;
}

void sub(int x, bool front){
    int v = arr[x];
    int d = dq[v].back() - dq[v].front();
    cnt[d]--, bkt[d/MSQ]--;
    if(front) dq[v].pop_front();
    else dq[v].pop_back();
    if(!dq[v].empty()){
        d = dq[v].back() - dq[v].front();
        cnt[d]++, bkt[d/MSQ]++;
    }
}

int qry(){
    for(int i=MBK-1; i>=0; i--){
        if(bkt[i] > 0){
            for(int j=MSQ-1; j>=0; j--){
                if(cnt[i*MSQ+j] > 0) return i*MSQ+j;
            }
        }
    }
    return 0;
}

int ans[MAX];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> arr[i];
    cin >> M;
    for(int i=0; i<M; i++){
        int l, r; cin >> l >> r;
        queries.emplace_back(l, r, i);
    }
    sort(queries.begin(), queries.end());

    for(int i=queries[0].l; i<=queries[0].r; i++) add(i, false);
    ans[queries[0].i] = qry();
    for(int i=1; i<M; i++){
        int l = queries[i-1].l, r = queries[i-1].r;
        int nl = queries[i].l, nr = queries[i].r;
        while(l > nl) add(--l, true);
        while(r < nr) add(++r, false);
        while(l < nl) sub(l++, true);
        while(r > nr) sub(r--, false);
        ans[queries[i].i] = qry();
    }

    for(int i=0; i<M; i++) cout << ans[i] << '\n';
}
