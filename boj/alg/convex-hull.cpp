// Convex hull finding with Graham's scan
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
struct Point {
    ll x, y;
    Point(): x(0), y(0) {}
    Point(ll x, ll y) : x(x), y(y) {}
};
vector<Point> points;

inline ll ccw(Point a, Point b, Point c) {
    return 1LL*(b.x-a.x)*(c.y-a.y) - 1LL*(b.y-a.y)*(c.x-a.x);
}

// convex hull finding with Graham's scan
vector<Point> hull;
void graham(){
    // find bottom-leftmost point
    int loc = 0;
    for (int i = 1; i < N; i++) if (points[i].y < points[loc].y || (points[i].y == points[loc].y && points[i].x < points[loc].x)) loc = i;

    // move point to front
    swap(points[0], points[loc]);

    // sort by polar angle
    sort(points.begin()+1, points.end(), [&](Point a, Point b) {
        ll ccw_val = ccw(points[0], a, b);
        if (ccw_val) return ccw_val > 0;
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    // find convex hull
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for (int i = 2; i < N; i++) {
        while (hull.size() >= 2) {
            Point a = hull.back(); hull.pop_back();
            Point b = hull.back();
            if (ccw(b, a, points[i]) > 0) {
                hull.push_back(a);
                break;
            }
        }
        hull.push_back(points[i]);
    }
}