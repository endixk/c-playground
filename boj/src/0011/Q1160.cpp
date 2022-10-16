// BOJ 1160 [Random Number Generator]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Matrix {
    ll a, b, c, d;
};

ll mul(ll a, ll b, ll m){
    ll ret = 0;
    while(b){
        if(b&1) ret = (ret+a)%m;
        a = (a+a)%m;
        b >>= 1;
    }
    return ret;
}

Matrix matmul(const Matrix& A, const Matrix& B, ll m){
    Matrix ret{};
    ret.a = (mul(A.a, B.a, m) + mul(A.b, B.c, m))%m;
    ret.b = (mul(A.a, B.b, m) + mul(A.b, B.d, m))%m;
    ret.c = (mul(A.c, B.a, m) + mul(A.d, B.c, m))%m;
    ret.d = (mul(A.c, B.b, m) + mul(A.d, B.d, m))%m;
    return ret;
}

Matrix matexp(const Matrix& A, ll p, ll m){
    if(p == 1) return A;
    Matrix ret = matexp(A, p/2, m);
    ret = matmul(ret, ret, m);
    if(p&1) ret = matmul(ret, A, m);
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll m, a, c, x, n ,g; cin >> m >> a >> c >> x >> n >> g;
    Matrix A = matexp({a, 0, c, 1}, n, m);
    ll ans = matmul({x, 1, 0, 0}, A, m).a;
    cout << ans % g;
}
