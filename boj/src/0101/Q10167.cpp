// BOJ 10167 [Gold Mines]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SEGMAX 8192

struct Node {
    ll lsum, rsum, tsum, msum;
    Node() : lsum(0), rsum(0), tsum(0), msum(0) {}
    explicit Node(ll x) : lsum(x), rsum(x), tsum(x), msum(x) {}
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
ll arr[SEGMAX];
void reset(){
    for(auto & i : seg) i = Node();
    fill(arr, arr+SEGMAX, 0);
}
void update(int i, ll x) {
    i += SEGMAX / 2;
    seg[i] = Node(x);
    while (i > 1) {
        i /= 2;
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

map<int,int> cmpx, cmpy; // compress x, y
vector<vector<pair<int,int>>> mines;
vector<tuple<int,int,int>> mv;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    for(int i=0; i<N; i++){
        int a, b, c; cin >> a >> b >> c;
        mv.emplace_back(a, b, c);
    }
    sort(mv.begin(), mv.end());

    // compress x, y
    list<int> cpx, cpy;
    for(auto [x, y, _] : mv){
        cpx.push_back(x);
        cpy.push_back(y);
    }
    cpx.sort(); cpy.sort();
    cpx.unique(); cpy.unique();

    int idx = 0;
    for(auto &i : cpx) cmpx[i] = ++idx;
    idx = 0;
    for(auto &i : cpy) cmpy[i] = idx++;

    mines.resize(idx);
    for(auto [x, y, w] : mv) mines[cmpy[y]].emplace_back(x, w);

    ll ans = 0;
    for(int i=0; i<idx; i++){
        // sweep
        reset();
        for(int j=i; j<idx; j++){
            for(auto [x, w] : mines[j]){
                arr[cmpx[x]] += w;
                update(cmpx[x], arr[cmpx[x]]);
            }
            ans = max(ans, seg[1].msum);
        }
    }
    cout << ans;
}
