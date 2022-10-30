// BOJ 1202 [A Jewel Thief]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> jewels;
vector<int> bags, pbag;
int uf_find(int x) {
    if(pbag[x] == x) return x;
    return pbag[x] = uf_find(pbag[x]);
}
void uf_union(int x, int y) {
    x = uf_find(x);
    y = uf_find(y);
    pbag[x] = y;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, K; cin >> N >> K;
    for(int i=0; i<N; ++i) {
        int M, V; cin >> M >> V;
        jewels.emplace_back(V, M);
    }
    sort(jewels.begin(), jewels.end(), greater<>());
    for(int i=0; i<K; ++i) {
        int C; cin >> C;
        bags.push_back(C);
        pbag.push_back(i);
    }
    sort(bags.begin(), bags.end());
    pbag.push_back(K);

    long long ans = 0;
    for(auto[v, m] : jewels) {
        int idx = (int)(lower_bound(bags.begin(), bags.end(), m) - bags.begin());
        int f = uf_find(idx);
        if(f == K) continue;
        ans += v;
        uf_union(f, f+1);
    }
    cout << ans;
}
