// BOJ 1161 [Shuttle]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int seg[1<<16], lazy[1<<16];

void propagate(int node, int s, int e){
    if(lazy[node]){
        seg[node] += lazy[node];
        if(s != e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int s, int e, int l, int r, int v){
    propagate(node, s, e);
    if(e < l || r < s) return;
    if(l <= s && e <= r){
        lazy[node] += v;
        propagate(node, s, e);
        return;
    }
    int m = (s+e)/2;
    update(node*2, s, m, l, r, v);
    update(node*2+1, m+1, e, l, r, v);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

int query(int node, int s, int e, int l, int r){
    propagate(node, s, e);
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return seg[node];
    int m = (s+e)/2;
    return max(query(node*2, s, m, l, r), query(node*2+1, m+1, e, l, r));
}

struct Group{
    int n, s, e;
    bool operator<(const Group& rhs) const {
        return e < rhs.e;
    }
};

int K, N, C, total;
vector<Group> groups;
void process(const Group& g){
    int q = query(1, 1, N, g.s, g.e);
    if(q < C){
        int v = min(C-q, g.n);
        update(1, 1, N, g.s, g.e-1, v);
        total += v;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> K >> N >> C;
    groups.resize(K);
    for(auto& g : groups) cin >> g.s >> g.e >> g.n;

    sort(groups.begin(), groups.end());
    for(auto& g : groups) process(g);
    cout << total;
}
