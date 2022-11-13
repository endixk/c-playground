// BOJ 13925 [Sequence and Queries 13]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001
#define SEG 262144
#define MOD 1000000007

ll arr[MAX], seg[SEG], mlazy[SEG], plazy[SEG];
void build(int node, int s, int e){
    if(s == e){
        seg[node] = arr[s];
        return;
    }
    int m = (s+e)/2;
    build(node*2, s, m);
    build(node*2+1, m+1, e);
    seg[node] = (seg[node*2] + seg[node*2+1]) % MOD;
}

void propagate(int node, int s, int e){
    if(mlazy[node] != 1){
        seg[node] = (seg[node] * mlazy[node]) % MOD;
        if(s != e){
            mlazy[node*2] = (mlazy[node*2] * mlazy[node]) % MOD;
            mlazy[node*2+1] = (mlazy[node*2+1] * mlazy[node]) % MOD;
            plazy[node*2] = (plazy[node*2] * mlazy[node]) % MOD;
            plazy[node*2+1] = (plazy[node*2+1] * mlazy[node]) % MOD;
        }
        mlazy[node] = 1;
    }
    if(plazy[node] != 0){
        seg[node] = (seg[node] + plazy[node] * (e-s+1)) % MOD;
        if(s != e){
            plazy[node*2] = (plazy[node*2] + plazy[node]) % MOD;
            plazy[node*2+1] = (plazy[node*2+1] + plazy[node]) % MOD;
        }
        plazy[node] = 0;
    }
}

void update(int node, int s, int e, int l, int r, ll m, ll p){
    propagate(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){
        mlazy[node] = (mlazy[node] * m) % MOD;
        plazy[node] = (plazy[node] + p) % MOD;
        propagate(node, s, e);
        return;
    }
    int mid = (s+e)/2;
    update(node*2, s, mid, l, r, m, p);
    update(node*2+1, mid+1, e, l, r, m, p);
    seg[node] = (seg[node*2] + seg[node*2+1]) % MOD;
}

ll query(int node, int s, int e, int l, int r){
    propagate(node, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return seg[node];
    int mid = (s+e)/2;
    return (query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r)) % MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    build(1, 1, N);
    fill(mlazy, mlazy+SEG, 1);

    int M; cin >> M;
    while(M--){
        int t; cin >> t;
        if(t == 1){
            int l, r; ll v; cin >> l >> r >> v;
            update(1, 1, N, l, r, 1, v);
        } else if(t == 2){
            int l, r; ll v; cin >> l >> r >> v;
            update(1, 1, N, l, r, v, 0);
        } else if(t == 3){
            int l, r; ll v; cin >> l >> r >> v;
            update(1, 1, N, l, r, 0, v);
        } else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, N, l, r) << '\n';
        }
    }
}
