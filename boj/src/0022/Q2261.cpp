// BOJ 2261 [Closest Pair]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator<(const Point &p) const {
        return y == p.y ? x < p.x : y < p.y;
    }
};

int dist(Point p, Point q){
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

set<Point> S;
vector<Point> V;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        V.emplace_back(x, y);
    }

    // sort points by x
    sort(V.begin(), V.end(), [](const Point &p, const Point &q) {
        return p.x < q.x;
    });

    S.insert(V[0]);
    S.insert(V[1]);
    int d = dist(V[0], V[1]);

    // sweep line
    int start = 0;
    for (int i = 2; i < n; i++){
        // reject points by x
        while(start < i){
            int x = V[i].x - V[start].x;
            if (x * x > d) S.erase(V[start++]);
            else break;
        }

        // find points by y
        auto lo = S.lower_bound(Point(-10000, V[i].y - (int)sqrt(d)));
        auto hi = S.upper_bound(Point(10000, V[i].y + (int)sqrt(d)));
        for(auto it = lo; it != hi; it++){
            d = min(d, dist(V[i], *it));
        }
        S.insert(V[i]);
    }

    cout << d;
}
