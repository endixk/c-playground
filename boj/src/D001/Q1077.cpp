// BOJ 1077 [Surface Area]
// Supported by GitHub Copilot

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
};
struct Line {
    Point ps, pe;
};
struct Polygon {
    vector<Point> points;
    vector<Line> lines;
};

bool inside(const Polygon& polygon, const Point& point){
    int cnt = 0;
    for (const Line& line : polygon.lines) {
        if (line.ps.y > point.y != line.pe.y > point.y) {
            double atX = (point.y - line.ps.y) / (line.pe.y - line.ps.y) * (line.pe.x - line.ps.x) + line.ps.x;
            if (atX > point.x) cnt++;
        }
        else if(line.ps.y == point.y){
            if (line.ps.x > point.x && line.pe.y > point.y) cnt++;
        }
        else if(line.pe.y == point.y){
            if (line.pe.x > point.x && line.ps.y > point.y) cnt++;
        }
    }
    return cnt % 2;
}

Point* intersection(const Line& lp, const Line& lq) {
    double denom = (lp.pe.x - lp.ps.x) * (lq.pe.y - lq.ps.y) - (lp.pe.y - lp.ps.y) * (lq.pe.x - lq.ps.x);
    if (denom == 0) return nullptr;

    double t = ((lp.ps.y - lq.ps.y) * (lq.pe.x - lq.ps.x) - (lp.ps.x - lq.ps.x) * (lq.pe.y - lq.ps.y)) / denom;
    double s = ((lp.ps.y - lq.ps.y) * (lp.pe.x - lp.ps.x) - (lp.ps.x - lq.ps.x) * (lp.pe.y - lp.ps.y)) / denom;

    if(t < 0 || t > 1 || s < 0 || s > 1) return nullptr;

    auto *p = new Point();
    p->x = lp.ps.x + t * (lp.pe.x - lp.ps.x);
    p->y = lp.ps.y + t * (lp.pe.y - lp.ps.y);
    return p;
}

double dist(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double ccw(const Point& p1, const Point& p2, const Point& p3){
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

double area(const Point& p1, const Point& p2, const Point& p3){
    return abs(ccw(p1, p2, p3)) / 2;
}

double area(const Polygon& polygon){
    double ret = 0;
    for (int i = 1; i < polygon.points.size() - 1; i++) {
        ret += area(polygon.points[0], polygon.points[i], polygon.points[i + 1]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    Polygon p1, p2;
    for (int i = 0; i < N; i++){
        double x, y; cin >> x >> y;
        Point tmp = {x, y};
        if(p1.points.size() > 1)
            if (ccw(p1.points[p1.points.size() - 2], p1.points.back(), tmp) == 0)
                p1.points.pop_back();
        p1.points.push_back({x, y});
    }
    for (int i = 0; i < M; i++){
        double x, y; cin >> x >> y;
        Point tmp = {x, y};
        if(p2.points.size() > 1)
            if(ccw(p2.points[p2.points.size() - 2], p2.points.back(), tmp) == 0)
                p2.points.pop_back();
        p2.points.push_back({x, y});
    }
    N = p1.points.size();
    M = p2.points.size();

    // generate lines
    for (int i = 0; i < N; i++) p1.lines.push_back({p1.points[i], p1.points[(i+1)%N]});
    for (int i = 0; i < M; i++) p2.lines.push_back({p2.points[i], p2.points[(i+1)%M]});

    vector<Point> overlap;
    for (const Line& lp : p1.lines){
        for (const Line& lq : p2.lines){
            Point* p = intersection(lp, lq);
            if (p != nullptr) overlap.push_back(*p);
        }
    }
    for (const Point& point : p1.points) if (inside(p2, point)) overlap.push_back(point);
    for (const Point& point : p2.points) if (inside(p1, point)) overlap.push_back(point);

    sort(overlap.begin(), overlap.end(), [](const Point& p1, const Point& p2){
        Point ori = {0, 0};
        double dir = ccw(ori, p1, p2);
        if(dir == 0) return dist(ori, p1) < dist(ori, p2);
        return dir > 0;
    });

    Polygon overlapPolygon;
    for(const Point& point : overlap) {
        if(overlapPolygon.points.size() > 1)
            if(ccw(overlapPolygon.points[overlapPolygon.points.size() - 2], overlapPolygon.points.back(), point) == 0)
                overlapPolygon.points.pop_back();
        overlapPolygon.points.push_back(point);
    }

    if(overlap.size() < 3){
        cout << 0.0;
        return 0;
    }

    cout.precision(15);
    cout << area(overlapPolygon);
}
