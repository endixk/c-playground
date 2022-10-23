// BOJ 4008 [Special Forces]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001

ll N, x[MAX], s[MAX], a, b, c;
ll dp[MAX];

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
    cin >> N >> a >> b >> c >> x[1];
    s[1] = x[1];
    for(int i=2; i<=N; i++) cin >> x[i], s[i] = s[i-1] + x[i];

    dp[0] = 0;
    int top = 0, pos = 0;
    for(int i=1; i<=N; i++){
        Line l(s[i-1], a*s[i-1]*s[i-1] - b*s[i-1] + dp[i-1]);
        while(top > 0){
            l.s = isct(v[top-1], l);
            if(v[top-1].s < l.s) break;
            if(--top == pos) pos--;
        }
        v[top++] = l;

        for(;pos < top-1 && v[pos+1].s < -2.0*a*s[i]; pos++);
        dp[i] = -2*a*s[i]*v[pos].a + a*s[i]*s[i] + b*s[i] + c + v[pos].b;
    }
    cout << dp[N];
}
