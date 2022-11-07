// BOJ 1206 [Number of People]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

bool pos[1001][1001];
bool valid[1001];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    memset(valid, true, sizeof(valid));
    for(int i=1; i<1001; ++i){
        for(int j=1; j<=i; ++j){
            pos[1000 * j / i % 1000][i] = true;
        }
    }

    int N; cin >> N;
    while(N--){
        string s; cin >> s;
        int k = stoi(s.substr(s.find('.') + 1));
        for(int i=1; i<1001; ++i){
            if(!pos[k][i]) valid[i] = false;
        }
    }
    for(int i=1; i<1001; ++i){
        if(valid[i]) return cout << i, 0;
    }
}
