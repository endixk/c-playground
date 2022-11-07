// BOJ 11012 [Egg]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 100002

// persistent segment tree
class Node{
public:
    int l, r, v;
    Node() : l(0), r(0), v(0) {}
    Node(int l, int r, int v) : l(l), r(r), v(v) {}
};

vector<Node> tree(2);
void init(int node, int s, int e){
    if(s == e) return;
    int m = (s+e)/2;
    tree.emplace_back();
    tree[node].l = (int)tree.size()-1;
    init(tree[node].l, s, m);
    tree.emplace_back();
    tree[node].r = (int)tree.size()-1;
    init(tree[node].r, m+1, e);
}

void update(int node, int s, int e, int idx, int val){
    if(s == e) return;
    int m = (s+e)/2;
    if(idx <= m){
        int l = tree[node].l;
        tree.emplace_back(tree[l].l, tree[l].r, tree[l].v+val);
        tree[node].l = (int)tree.size()-1;
        update(tree[node].l, s, m, idx, val);
    }
    else{
        int r = tree[node].r;
        tree.emplace_back(tree[r].l, tree[r].r, tree[r].v+val);
        tree[node].r = (int)tree.size()-1;
        update(tree[node].r, m+1, e, idx, val);
    }
}

int query(int node, int s, int e, int l, int r){
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node].v;
    int m = (s+e)/2;
    return query(tree[node].l, s, m, l, r) + query(tree[node].r, m+1, e, l, r);
}

int root[MAX];
vector<int> Y[MAX];
void reset(){
    tree.clear();
    tree.resize(2);
    for(auto & y : Y) y.clear();
    fill(root, root+MAX, 0);
    init(1, 1, MAX);
    root[0] = 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        reset();
        int N, M; cin >> N >> M;
        while(N--){
            int x, y; cin >> x >> y;
            Y[++y].push_back(++x);
        }
        for(int i=1; i<MAX; ++i){
            tree.emplace_back(tree[root[i-1]].l, tree[root[i-1]].r, tree[root[i-1]].v);
            root[i] = (int)tree.size()-1;
            for(int x : Y[i]) {
                tree[root[i]].v++;
                update(root[i], 1, MAX, x, 1);
            }
        }
        int ans = 0;
        while(M--){
            int l, r, b, t; cin >> l >> r >> b >> t;
            l++, r++, b++, t++;
            ans += query(root[t], 1, MAX, l, r) - query(root[b-1], 1, MAX, l, r);
        }
        cout << ans << '\n';
    }
}
