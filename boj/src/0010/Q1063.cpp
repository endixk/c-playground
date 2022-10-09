// BOJ 1063 [King]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

string next(const string &loc, const string &move){
    int x = loc[0] - 'A', y = loc[1] - '1';
    switch(move[0]) {
        case 'R': x++; break;
        case 'L': x--; break;
        case 'B': y--; break;
        case 'T': y++; break;
    }
    if(move.size() > 1){
        switch(move[1]) {
            case 'B': y--; break;
            case 'T': y++; break;
        }
    }
    if(x < 0 || x > 7 || y < 0 || y > 7) return loc;
    return string(1, 'A' + x) + string(1, '1' + y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string k, s; int n;
    cin >> k >> s >> n;
    string moves[n];
    for(int i = 0; i < n; i++) cin >> moves[i];

    for(int i = 0; i < n; i++){
        string nk = next(k, moves[i]);
        if(nk == k) continue;
        if(nk == s){
            string ns = next(s, moves[i]);
            if(ns == s) continue;
            s = ns;
        }
        k = nk;
    }

    cout << k << '\n' << s << '\n';
}
