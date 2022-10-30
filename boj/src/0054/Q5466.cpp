// BOJ 5466 [Salesman]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 500005
#define SEGMAX 1048576
#define INF 999999999

int segd[SEGMAX], segu[SEGMAX];
void update(int *seg, int i, int v) {
    i |= SEGMAX >> 1;
    seg[i] = v;
    while (i >>= 1) seg[i] = max(seg[i<<1], seg[i<<1|1]);
}
int query(int *seg, int l, int r) {
    l |= SEGMAX >> 1, r |= SEGMAX >> 1;
    int ret = -INF;
    while (l <= r) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (~r & 1) ret = max(ret, seg[r--]);
        l >>= 1, r >>= 1;
    }
    return ret;
}

struct Market {
    int T, L, M;
    Market() : T(0), L(0), M(0) {}
    Market(int T, int L, int M) : T(T), L(L), M(M) {}
    bool operator<(const Market &rhs) const {
        if(T == rhs.T) return L < rhs.L;
        return T < rhs.T;
    }
};

vector<Market> markets;
vector<vector<int>> days;
int dp[MAX];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // input
    int N, U, D, S; cin >> N >> U >> D >> S;
    int maxL = S;
    for(int i=0; i<N; i++){
        int T, L, M; cin >> T >> L >> M;
        markets.emplace_back(T, L, M);
        maxL = max(maxL, L);
    }

    // preprocess markets
    sort(markets.begin(), markets.end());
    for(int i=0, d; i<=N; i++){
        if(markets[i].T != d){
            d = markets[i].T;
            days.emplace_back();
        }
        days.back().push_back(i);
    }

    fill(segd, segd+SEGMAX, -INF);
    fill(segu, segu+SEGMAX, -INF);
    update(segd, S, S*D);
    update(segu, S, -S*U);

    // dp
    int mkt = 0;
    for(const auto& dv : days){
        vector<Market> v;
        for(int i : dv) v.push_back(markets[i]);
        int sz = (int)v.size(), d[sz], u[sz];
        // direct routes
        for(int i=0; i<sz; i++){
            int q = max(query(segd, 0, v[i].L) - v[i].L * D, query(segu, v[i].L, maxL) + v[i].L * U);
            d[i] = u[i] = q + v[i].M;
        }
        // adjacent routes
        for(int i=1; i<sz; i++) d[i] = max(d[i], d[i-1] - (v[i].L - v[i-1].L) * D + v[i].M);
        for(int i=sz-2; i>=0; i--) u[i] = max(u[i], u[i+1] - (v[i+1].L - v[i].L) * U + v[i].M);
        // update
        for(int i=0; i<sz; i++){
            dp[mkt+i] = max(d[i], u[i]);
            update(segd, v[i].L, dp[mkt+i] + v[i].L * D);
            update(segu, v[i].L, dp[mkt+i] - v[i].L * U);
        }
        mkt += sz;
    }

    // output
    cout << max(query(segd, 0, S) - S*D, query(segu, S, maxL) + S*U);
}
