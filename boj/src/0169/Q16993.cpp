// BOJ 16993 [Consecutive Sum and Queries]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SEGMAX 262144
#define INF 0x3f3f3f3f

struct Node {
    int lsum, rsum, tsum, msum;
    Node() : lsum(-INF), rsum(-INF), tsum(-INF), msum(-INF) {}
    explicit Node(int x) : lsum(x), rsum(x), tsum(x), msum(x) {}
    Node operator+(const Node &rhs) const {
        Node ret;
        ret.lsum = max(lsum, tsum + rhs.lsum);
        ret.rsum = max(rhs.rsum, rhs.tsum + rsum);
        ret.tsum = tsum + rhs.tsum;
        ret.msum = max({msum, rhs.msum, rsum + rhs.lsum});
        return ret;
    }
};

Node seg[SEGMAX];
void update(int i, int x) {
    i += SEGMAX / 2;
    seg[i] = Node(x);
    while (i > 1) {
        i /= 2;
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}
Node query(int l, int r) {
    l += SEGMAX / 2;
    r += SEGMAX / 2;
    Node retl, retr;
    while (l <= r) {
        if (l % 2 == 1) retl = retl + seg[l++];
        if (r % 2 == 0) retr = seg[r--] + retr;
        l /= 2;
        r /= 2;
    }
    return retl + retr;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    for(int i=1; i<=N; ++i) {
        int x; cin >> x;
        update(i, x);
    }
    int M; cin >> M;
    while(M--){
        int i, j; cin >> i >> j;
        cout << query(i, j).msum << '\n';
    }
}
