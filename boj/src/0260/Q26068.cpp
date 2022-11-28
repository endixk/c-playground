// BOJ Contest 895-A
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, c=0; cin >> N;
    while(N--){
        string s; cin >> s;
        c += stoi(s.substr(2)) < 91;
    }
    cout << c;
}
