// BOJ 13517 [Tree and Queries 8]
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

int root[MAX], arr[MAX], depth[MAX], parent[MAX][20];
vector<int> graph[MAX];

// generate LCA tables and persistent segment tree
void generate(int cur, int par, int d){
    depth[cur] = d;
    parent[cur][0] = par;
    for (int i = 1; i < 20; i++) parent[cur][i] = parent[parent[cur][i - 1]][i - 1];

    tree.emplace_back(tree[root[par]].l, tree[root[par]].r, tree[root[par]].v);
    root[cur] = (int)tree.size()-1;
    update(root[cur], 1, MAX-1, arr[cur], 1);

    for (auto nxt : graph[cur]) {
        if (nxt == par) continue;
        generate(nxt, cur, d + 1);
    }
}

// find LCA
int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);

    // move u to same depth with v
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - depth[v] >= (1 << i)) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;

    // move u and v to same parent
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    // return LCA
    return parent[u][0];
}

int query(int u, int v, int ca, int pca, int s, int e, int k){
    if(s == e) return s;
    int m = (s+e)/2;
    int diff = tree[tree[u].l].v + tree[tree[v].l].v - tree[tree[ca].l].v - tree[tree[pca].l].v;
    if(k <= diff) return query(tree[u].l, tree[v].l, tree[ca].l, tree[pca].l, s, m, k);
    else return query(tree[u].r, tree[v].r, tree[ca].r, tree[pca].r, m+1, e, k-diff);
}

int val[MAX], tmp[MAX];
map<int,int> mp;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> val[i], tmp[i] = val[i];
    sort(tmp, tmp+N);
    for(int i=0; i<N; i++) mp[tmp[i]] = i+1;
    for(int i=0; i<N; i++) arr[i+1] = mp[val[i]];

    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    init(1, 1, MAX);
    root[0] = 1;
    generate(1, 0, 0);

    int M; cin >> M;
    while(M--){
        int u, v, k; cin >> u >> v >> k;
        int ca = lca(u, v);
        cout << tmp[query(root[u], root[v], root[ca], root[parent[ca][0]], 1, MAX-1, k)-1] << '\n';
    }
}
