// BOJ 1708 [Convex Hull]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {ll x, y;};
vector<Point> points;

ll ccw(Point a, Point b, Point c) {
    return 1LL*(b.x-a.x)*(c.y-a.y) - 1LL*(b.y-a.y)*(c.x-a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        points.push_back({x, y});
    }

    // find bottom-leftmost point
    int loc= 0;
    for (int i = 1; i < N; i++) if (points[i].y < points[loc].y || (points[i].y == points[loc].y && points[i].x < points[loc].x)) loc = i;


    // move point to first
    swap(points[0], points[loc]);

    // sort by angle
    sort(points.begin()+1, points.end(), [&](Point a, Point b) {
        ll ccw_val = ccw(points[0], a, b);
        if (ccw_val) return ccw_val > 0;
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    // Graham scan
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    for (int i = 2; i < N; i++) {
        while (hull.size() >= 2) {
            Point a = hull.top(); hull.pop();
            Point b = hull.top();
            if (ccw(b, a, points[i]) > 0) {
                hull.push(a);
                break;
            }
        }
        hull.push(points[i]);
    }

    cout << hull.size();
}
