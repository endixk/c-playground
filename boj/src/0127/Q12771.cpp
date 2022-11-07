// BOJ 12771 [Oil]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 2001

int N, S[MAX], E[MAX], Y[MAX];
int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long k = 1LL*(x2-x1)*(y3-y1) - 1LL*(x3-x1)*(y2-y1);
    if(k > 0) return 1;
    if(k < 0) return -1;
    return 0;
}

struct Point {
    int x, y, v;
    Point(int x, int y, int v) : x(x), y(y), v(v) {}
    bool operator<(const Point& p) const {
        int k = ccw(0, 0, x, y, p.x, p.y);
        if(k == 0) return v > p.v;
        return k < 0;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> S[i] >> E[i] >> Y[i];
        if(S[i] > E[i]) swap(S[i], E[i]);
    }

    int ans = 0;
    for(int i=0; i<2*N; ++i){
        int x = i%2 ? E[i/2] : S[i/2], y = Y[i/2];
        vector<Point> v;
        for(int j=0; j<N; ++j){
            int ps = S[j], pe = E[j], py = Y[j];
            if(py == y) continue;
            if(py > y){
                v.emplace_back(ps-x, py-y, pe-ps);
                v.emplace_back(pe-x, py-y, ps-pe);
            }
            else{
                v.emplace_back(x-pe, y-py, pe-ps);
                v.emplace_back(x-ps, y-py, ps-pe);
            }
        }

        sort(v.begin(), v.end());
        int val = E[i/2] - S[i/2];
        ans = max(ans, val);
        for(auto &p : v){
            val += p.v;
            ans = max(ans, val);
        }
    }
    cout << ans;
}
