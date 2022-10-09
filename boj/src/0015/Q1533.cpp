// BOJ 1533 [Number of Roads]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

#define MOD 1000003LL
matrix operator * (const matrix &a, const matrix &b) {
    size_t n = a.size();
    matrix c(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    return c;
}
matrix power(const matrix &M, ll n){
    if (n == 1) return M;
    matrix half = power(M, n / 2);
    if (n % 2) return M * half * half;
    return half * half;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, S, E, T; cin >> N >> S >> E >> T;
    matrix M(5*N+1, vector<ll>(5*N+1));
    for(int i=1; i<=N; ++i){
        string s; cin >> s;
        for(int j=1; j<=N; ++j){
            if(s[j-1] == '0') continue;
            int val = s[j-1] - '1';
            M[5*i][5*j-val] = 1;
            for(int k=val; k>0; --k) M[5*j-k][5*j-k+1] = 1;
        }
    }
    M = power(M, T);
    cout << M[5*S][5*E];
}
