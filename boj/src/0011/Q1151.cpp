// BOJ 1151 [Shadow]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct Point3D {int x, y, z;};
struct Point2D {double x, y;};

double ccw(Point2D a, Point2D b, Point2D c) {
    return 1LL*(b.x-a.x)*(c.y-a.y) - 1LL*(b.y-a.y)*(c.x-a.x);
}

double area(const vector<Point2D>& points) {
    double ret = 0;
    for (int i = 1; i < points.size()-1; i++) {
        ret += abs(ccw(points[0], points[i], points[i+1])) / 2;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    int lx, ly, lz; cin >> lx >> ly >> lz;
    Point3D light = {lx, ly, lz};

    vector<Point3D> points;
    points.push_back({x1, y1, z1});
    if(z1 != z2) points.push_back({x1, y1, z2});
    if(y1 != y2) {
        points.push_back({x1, y2, z1});
        if(z1 != z2) points.push_back({x1, y2, z2});
    }
    if(x1 != x2) {
        points.push_back({x2, y1, z1});
        if(z1 != z2) points.push_back({x2, y1, z2});
        if(y1 != y2) {
            points.push_back({x2, y2, z1});
            if(z1 != z2) points.push_back({x2, y2, z2});
        }
    }

    if(points.size() < 3){
        cout << 0;
        return 0;
    }

    // define plane using light, points[0], points[1]
    int a = light.y*(points[0].z-points[1].z) +
            points[0].y*(points[1].z-light.z) +
            points[1].y*(light.z-points[0].z);
    int b = light.z*(points[0].x-points[1].x) +
            points[0].z*(points[1].x-light.x) +
            points[1].z*(light.x-points[0].x);
    int c = light.x*(points[0].y-points[1].y) +
            points[0].x*(points[1].y-light.y) +
            points[1].x*(light.y-points[0].y);
    int d = -light.x*(points[0].y*points[1].z-points[1].y*points[0].z)
            -points[0].x*(light.y*points[1].z-points[1].y*light.z)
            -points[1].x*(points[0].y*light.z-light.y*points[0].z);

    // check if other points are in the same side of the plane
    bool shadow_exist = false;
    for(int i = 2; i < points.size(); i++){
        int val = a*points[i].x + b*points[i].y + c*points[i].z + d;
        if(val != 0){
            shadow_exist = true;
            break;
        }
    }

    if(!shadow_exist){
        cout << 0;
        return 0;
    }

    // check infinity
    for(Point3D p : points){
        if(p.z >= light.z){
            cout << -1;
            return 0;
        }
    }

    // find projections on xy plane
    vector<Point2D> prjs;
    for(Point3D p : points){
        double x = (double)light.x - (double)light.z*(p.x-light.x)/(p.z-light.z);
        double y = (double)light.y - (double)light.z*(p.y-light.y)/(p.z-light.z);
        prjs.push_back({x, y});
    }

    // find bottom-left point
    int loc = 0;
    for(int i=0; i<prjs.size(); i++){
        if(prjs[i].y < prjs[loc].y || (prjs[i].y == prjs[loc].y && prjs[i].x < prjs[loc].x)) loc = i;
    }
    swap(prjs[0], prjs[loc]);

    // sort by angle
    sort(prjs.begin()+1, prjs.end(), [&](Point2D a, Point2D b) {
        double ccw_val = ccw(prjs[0], a, b);
        if (ccw_val != 0) return ccw_val > 0;
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    // find convex hull
    vector<Point2D> hull;
    hull.push_back(prjs[0]);
    hull.push_back(prjs[1]);
    for(int i=2; i<prjs.size(); i++){
        while(hull.size() >= 2){
            Point2D p1 = hull[hull.size()-2];
            Point2D p2 = hull[hull.size()-1];
            if(ccw(p1, p2, prjs[i]) > 0) break;
            hull.pop_back();
        }
        hull.push_back(prjs[i]);
    }

    cout << fixed << setprecision(10) << area(hull);
}
