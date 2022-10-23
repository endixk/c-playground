// BOJ 1199 [Eulerian Circuit]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int N, adj[MAX][MAX], deg[MAX];
bool visited[MAX];
void conn(int v){
    visited[v] = true;
    for(int i=0; i<N; i++){
        if(adj[v][i] && !visited[i]) conn(i);
    }
}

int seg[MAX][1<<11];
void build(int v, int node, int s, int e){
    if(s == e){
        seg[v][node] = adj[v][s];
        return;
    }
    int m = (s+e)/2;
    build(v, node*2, s, m);
    build(v, node*2+1, m+1, e);
    seg[v][node] = seg[v][node*2] + seg[v][node*2+1];
}
int update(int v, int node, int s, int e, int idx){
    if(idx < s || e < idx) return seg[v][node];
    if(s == e){
        seg[v][node]--;
        return seg[v][node];
    }
    int m = (s+e)/2;
    return seg[v][node] = update(v, node*2, s, m, idx) + update(v, node*2+1, m+1, e, idx);
}
int query(int v, int node, int s, int e, int k){
    if(s == e) return s;
    int m = (s+e)/2;
    if(seg[v][node*2] >= k) return query(v, node*2, s, m, k);
    else return query(v, node*2+1, m+1, e, k-seg[v][node*2]);
}

// Heirholzer's algorithm
void dfs(int v){
    while(seg[v][1] > 0){
        int u = query(v, 1, 0, N-1, 1);
        update(v, 1, 0, N-1, u);
        update(u, 1, 0, N-1, v);
        dfs(u);
    }
    cout << v+1 << ' ';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cin >> adj[i][j];
            deg[i] += adj[i][j];
        }
    }

    // check existence
    for(int i=0; i<N; i++){
        if(deg[i] % 2) {
            cout << -1;
            return 0;
        }
    }

    // check connectedness
    conn(0);
    for(int i=0; i<N; i++){
        if(!visited[i]){
            cout << -1;
            return 0;
        }
    }

    // build segment tree
    for(int i=0; i<N; i++) build(i, 1, 0, N-1);
    dfs(0);
}
