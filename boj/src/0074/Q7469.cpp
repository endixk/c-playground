// BOJ 7469 [K-th number]
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

// query k-th element in [l, r]
int query(int node1, int node2, int s, int e, int k){
    if(s == e) return s;
    int m = (s+e)/2;
    int diff = tree[tree[node1].l].v - tree[tree[node2].l].v;
    if(k <= diff) return query(tree[node1].l, tree[node2].l, s, m, k);
    else return query(tree[node1].r, tree[node2].r, m+1, e, k-diff);
}

int root[MAX], arr[MAX], tmp[MAX];
map<int,int> M, R;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    for(int i=0; i<N; i++) cin >> arr[i], tmp[i] = arr[i];
    sort(tmp, tmp+N);
    for(int i=0; i<N; i++) M[tmp[i]] = i+1, R[i+1] = tmp[i];

    init(1, 1, MAX);
    root[0] = 1;
    for(int i=1; i<=N; i++){
        int x = M[arr[i-1]];
        tree.emplace_back(tree[root[i-1]].l, tree[root[i-1]].r, tree[root[i-1]].v);
        root[i] = (int)tree.size()-1;
        update(root[i], 1, MAX, x, 1);
        tree[root[i]].v++;
    }
    while(Q--){
        int i, j, k; cin >> i >> j >> k;
        cout << R[query(root[j], root[i-1], 1, MAX, k)] << '\n';
    }
}
