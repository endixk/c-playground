// BOJ 2336 [Magnificent Students]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define SEG 1<<20
#define INF 999999999

int N;
vector<tuple<int,int,int>> ranks;
int seg[SEG];

// min-segment tree
void update(int node, int s, int e, int i, int v){
    if(i < s || e < i) return;
    if(s == e){
        seg[node] = v;
        return;
    }
    int m = (s+e)/2;
    update(node*2, s, m, i, v);
    update(node*2+1, m+1, e, i, v);
    seg[node] = min(seg[node*2], seg[node*2+1]);
}
int query(int node, int s, int e, int l, int r){
    if(r < s || e < l) return INF;
    if(l <= s && e <= r) return seg[node];
    int m = (s+e)/2;
    return min(query(node*2, s, m, l, r), query(node*2+1, m+1, e, l, r));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    ranks.resize(N);
    for(int s,i=1; i<=N; i++) cin >> s, get<0>(ranks[s-1]) = i;
    for(int s,i=1; i<=N; i++) cin >> s, get<1>(ranks[s-1]) = i;
    for(int s,i=1; i<=N; i++) cin >> s, get<2>(ranks[s-1]) = i;
    sort(ranks.begin(), ranks.end());
    for(auto &s : seg) s = INF;

    int ans = 0;
    for(int i=0; i<N; i++){
        int idx = get<1>(ranks[i]);
        int val = get<2>(ranks[i]);
        if(query(1, 1, N, 1, idx) > val) ans++;
        update(1, 1, N, idx, val);
    }
    cout << ans;
}
