// BOJ 1076 [Resistance]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> rmap = {
        {"black", 0},
        {"brown", 1},
        {"red", 2},
        {"orange", 3},
        {"yellow", 4},
        {"green", 5},
        {"blue", 6},
        {"violet", 7},
        {"grey", 8},
        {"white", 9}
    };

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int base = rmap[s1] * 10 + rmap[s2];
    if(base == 0) cout << 0;
    else {
        cout << base;
        for(int i=0; i<rmap[s3]; i++) cout << 0;
    }
}
