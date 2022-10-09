// BOJ 1100 [White Space]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    for(int i=1; i<9; i++){
        string s; cin >> s;
        for(int j=0; j<8; j++) cnt += (i+j)%2 && s[j]=='F';
    }
    cout << cnt;
}
