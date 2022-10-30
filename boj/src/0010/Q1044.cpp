// BOJ 1044 [Team Selection]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,int> L[20], R[20];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    ll A[N], B[N];
    for (int i=0; i<N; ++i) cin >> A[i];
    for (int i=0; i<N; ++i) cin >> B[i];

    // left half
    for(int i=0; i<(1<<(N/2)); ++i){
        ll v = 0; int cnt = 0;
        for(int j=0; j<N/2; ++j){
            if(i&(1<<j)) v -= B[N/2-1-j];
            else v += A[N/2-1-j], cnt++;
        }
        if(L[cnt].find(v) == L[cnt].end()) L[cnt][v] = i;
    }
    // right half
    for(int i=0; i<(1<<(N/2)); ++i){
        ll v = 0; int cnt = 0;
        for(int j=0; j<N/2; ++j){
            if(i&(1<<j)) v -= B[N-1-j];
            else v += A[N-1-j], cnt++;
        }
        if(R[cnt].find(v) == R[cnt].end()) R[cnt][v] = i;
    }

    int ml = 0, mr = 0; ll mv = INT64_MAX;
    for(int i=0; i<=N/2; ++i){
        if(L[i].empty() || R[N/2-i].empty()) continue;
        for(auto [v, l] : L[i]){
            auto it = R[N/2-i].lower_bound(-v);
            if(it != R[N/2-i].end()){
                ll nv = abs(v + it->first);
                if(nv < mv) mv = nv, ml = l, mr = it->second;
                else if(nv == mv){
                    if(l < ml) ml = l, mr = it->second;
                    else if(l == ml && it->second < mr) mr = it->second;
                }
            }
            if(it != R[N/2-i].begin()){
                --it;
                ll nv = abs(v + it->first);
                if(nv < mv) mv = nv, ml = l, mr = it->second;
                else if(nv == mv){
                    if(l < ml) ml = l, mr = it->second;
                    else if(l == ml && it->second < mr) mr = it->second;
                }
            }
        }
    }

    for(int i=0; i<N/2; ++i){
        if(ml&(1<<(N/2-1-i))) cout << "2 ";
        else cout << "1 ";
    }
    for(int i=0; i<N/2; ++i){
        if(mr&(1<<(N/2-1-i))) cout << "2 ";
        else cout << "1 ";
    }
}
