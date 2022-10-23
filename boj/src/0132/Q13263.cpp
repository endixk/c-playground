// BOJ 13263 [Cutting Trees]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

ll N, A[MAX], B[MAX], dp[MAX];

struct Line{
    ll a, b;
    double s;
    Line(): a(0), b(0), s(0) {}
    Line(ll a, ll b): a(a), b(b) {s=0;}
};
double isct(const Line& l1, const Line& l2){
    return (double)(l2.b - l1.b) / (double)(l1.a - l2.a);
}

Line v[MAX];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];

    dp[0] = 0;
    int top = 0, pos = 0;
    for(int i=1; i<N; i++){
        Line l(B[i-1], dp[i-1]);
        while(top > 0){
            l.s = isct(v[top-1], l);
            if(v[top-1].s < l.s) break;
            if(--top == pos) pos--;
        }
        v[top++] = l;

        for(;pos < top-1 && v[pos+1].s < (double)A[i]; pos++);
        dp[i] = v[pos].a * A[i] + v[pos].b;
    }
    cout << dp[N-1];
}
