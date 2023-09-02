#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

int N;
ll L, R[MAX];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++) {
        ll l; cin >> l;
        R[i+1] = R[i] + l;
    }
    cin >> L;

    int q; cin >> q;
    for(int i=0; i<q; i++) {
        int t; cin >> t;
        ll loc = R[t] + R[t-1] - L;
        if(loc > 2 * (R[N] - L)) loc = 2 * (R[N] - L);
        if(loc < 0) loc = 0;
        cout << fixed << setprecision(2) << (double) loc / 2 << '\n';
    }
}
