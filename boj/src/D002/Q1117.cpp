// BOJ 1117 [Coloring]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long W, H, f, c, x1, y1, x2, y2;
    cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

    long long ans = 0;
    if(f > W/2){
        if(x2 <= W - f) ans += 2 * (x2 - x1);
        else if(x1 >= W - f) ans += x2 - x1;
        else ans += 2 * (W - f - x1) + x2 - W + f;
    }
    else{
        if(x2 <= f) ans += 2 * (x2 - x1);
        else if(x1 >= f) ans += x2 - x1;
        else ans += 2 * (f - x1) + x2 - f;
    }

    cout << W*H - ans * (y2 - y1) * (c + 1);
}
