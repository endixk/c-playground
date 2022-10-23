// BOJ 1198 [Cutting into a Triangle]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

double area(pii x, pii y, pii z){
    return abs(x.first*y.second + y.first*z.second + z.first*x.second - x.second*y.first - y.second*z.first - z.second*x.first) / 2.0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> v(n);
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;

    double ans = 0;
    for(int i=0; i<n-2; i++)
        for(int j=i+1; j<n-1; j++)
            for(int k=j+1; k<n; k++)
                ans = max(ans, area(v[i], v[j], v[k]));
    cout << fixed << setprecision(15) << ans;
}
