// BOJ 1064 [Parallelogram]
// Supported by GitHub Copilot

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    // test if the three points are on the same line
    if((xb - xa) * (yc - ya) == (xc - xa) * (yb - ya)){
        cout << -1 << '\n';
        return 0;
    }

    // get distances
    int sqab = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb),
        sqac = (xa - xc) * (xa - xc) + (ya - yc) * (ya - yc),
        sqbc = (xb - xc) * (xb - xc) + (yb - yc) * (yb - yc);
    int MAX = max(sqab, max(sqac, sqbc)),
        MIN = min(sqab, min(sqac, sqbc));

    // print output
    cout << setprecision(20) << (double) 2 * (sqrt(MAX) - sqrt(MIN)) << '\n';
}
