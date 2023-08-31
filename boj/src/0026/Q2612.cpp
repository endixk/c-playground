// BOJ 2612 [DNA Similiarity]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1004

int N, M, dp[MAX][MAX], tr[MAX][MAX]; // 0: *, 1: X-, 2: -Y, 3: XY
string S, T;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> S >> M >> T;

    // Smith-Waterman algorithm
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            int d = 0;
            if (d < dp[i-1][j] - 2) {
                d = dp[i-1][j] - 2;
                tr[i][j] = 1;
            }
            if (d < dp[i][j-1] - 2) {
                d = dp[i][j-1] - 2;
                tr[i][j] = 2;
            }
            int m = S[i-1] == T[j-1] ? 3 : -2;
            if (d < dp[i-1][j-1] + m) {
                d = dp[i-1][j-1] + m;
                tr[i][j] = 3;
            }
            dp[i][j] = d;
        }
    }

    // find max
    int x = 0, y = 0, d = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (d < dp[i][j]) { d = dp[i][j]; x = i; y = j; }
        }
    }

    // backtrack
    string a, b;
    while (x && y) {
        if (tr[x][y] == 0) { break;}
        else if (tr[x][y] == 1) { a += S[--x]; }
        else if (tr[x][y] == 2) { b += T[--y]; }
        else { a += S[--x]; b += T[--y]; }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << d << '\n' << a << '\n' << b;
}
