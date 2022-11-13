// BOJ 1215 [Miswritten Code for the Josephus Problem]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A, T, B;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, K; cin >> N >> K;

    for(int i=1; i*i<=K; ++i){
        A.push_back(i);
        T.push_back(K/i);
    }
    for(int i=(int)A.size()-1; i>=0; --i) A.push_back(T[i]);

    int t = 0;
    for(int a : A) B.push_back(a-t), t = a;

    ll r = 0, s = 0, i = 0;
    while(i < (int)A.size()){
        ll p, q;
        if(s + B[i] > N) p = s, q = N;
        else p = s, q = s + B[i];

        r += A[(int)A.size()-i-1] * (q*(q+1)/2 - p*(p+1)/2);
        s += B[i++];
        if(s >= N) break;
    }
    cout << (ll)N*K - r << '\n';
}
