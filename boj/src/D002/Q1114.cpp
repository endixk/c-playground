// BOJ 1114 [Cutting the Log]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
using namespace std;

int L, K, C, loc[10005];

int possible(int len){
    int buf = L, cut = 0;
    for(int i=K; i>0; i--){
        if(buf - loc[i] > len) return -1;
        if(buf - loc[i-1] > len){
            buf = loc[i];
            cut++;
        }
        if(cut == C) break;
    }
    if(cut < C) buf = loc[1];
    if(buf > len) return -1;
    return buf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> L >> K >> C;
    loc[0] = 0;
    for (int i = 0; i < K; i++) cin >> loc[i+1];
    sort(loc, loc+K+1);

    int l = 1, r = L, ret = 0;
    for(int i=0; i<40; i++){
        if(possible((l+r)/2) < 0) l = (l+r)/2 + 1;
        else {
            ret = (l+r)/2;
            r = (l+r)/2 - 1;
        }
    }

    cout << ret << ' ' << possible(ret);
}
