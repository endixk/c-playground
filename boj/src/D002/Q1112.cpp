// BOJ 1122 [Number System]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, b; cin >> x >> b;
    if(x == 0) {
        cout << 0;
        return 0;
    }
    bool ex = false;
    if(b > 0 && x < 0) {
        x = -x;
        ex = true;
    }

    string s;
    while(x){
        char c = '0' + (x > 0 ? x % b : (x % b ? x % b + abs(b) : 0));
        s = c + s;
        x = x > 0 ? x / b : (x % b ? x / b + 1 : x / b);
    }

    if(ex) cout << '-';
    cout << s;
}
