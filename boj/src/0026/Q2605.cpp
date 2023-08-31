// BOJ 2605 [Line Up]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        A.insert(A.end()-a, i+1);
    }
    for(int x : A) cout << x << ' ';
}
