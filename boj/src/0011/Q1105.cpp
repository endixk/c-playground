// BOJ 1105 [Eight]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string l, r; cin >> l >> r;
    if(l.length() < r.length()) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < l.length(); i++) {
        if(l[i] != r[i]) break;
        if(l[i] == '8') ans++;
    }
    cout << ans;
}
