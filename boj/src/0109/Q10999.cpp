// BOJ 10999 [Interval Sum 2]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
typedef long long ll;

ll arr[MAX], seg[1<<21], lazy[1<<21];

void build(int node, int s, int e) {
    if (s == e) {
        seg[node] = arr[s];
        return;
    }
    int m = (s+e)/2;
    build(node*2, s, m);
    build(node*2+1, m+1, e);
    seg[node] = seg[node*2] + seg[node*2+1];
}

void propagate(int node, int s, int e){
    if(lazy[node]){
        seg[node] += (e-s+1)*lazy[node];
        if(s != e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int s, int e, int l, int r, ll v){
    propagate(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){
        seg[node] += (e-s+1)*v;
        if(s != e){
            lazy[node*2] += v;
            lazy[node*2+1] += v;
        }
        return;
    }
    int m = (s+e)/2;
    update(node*2, s, m, l, r, v);
    update(node*2+1, m+1, e, l, r, v);
    seg[node] = seg[node*2] + seg[node*2+1];
}

ll query(int node, int s, int e, int l, int r){
    propagate(node, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return seg[node];
    int m = (s+e)/2;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M, K; cin >> N >> M >> K;
    for(int i=1; i<=N; i++) cin >> arr[i];
    build(1, 1, N);
    for(int i=0; i<M+K; i++){
        int t; cin >> t;
        if(t == 1){
            int l, r; ll v; cin >> l >> r >> v;
            update(1, 1, N, l, r, v);
        }
        else{
            int l, r; cin >> l >> r;
            cout << query(1, 1, N, l, r) << '\n';
        }
    }
}
