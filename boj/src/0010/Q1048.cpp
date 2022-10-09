// BOJ 1048 [Unicorn]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

#define DIV 1000000007LL

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L; cin >> N >> M >> L;
    string s; cin >> s;

    string board[N];
    for (int i=0; i<N; i++) cin >> board[i];

    int curr[N][M];
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            curr[i][j] = (board[i][j] == s[0] ? 1 : 0);

    for (int c=1; c<s.length(); c++){
        // prefix sum
        int prefix[N+1][M+1];
        for (int i=0; i<=N; i++)
            for (int j=0; j<=M; j++)
                prefix[i][j] = 0;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                long long tmp =
                        (long long) curr[i-1][j-1] +
                        (long long) prefix[i-1][j] +
                        (long long) prefix[i][j-1] -
                        (long long) prefix[i-1][j-1] +
                        2LL * DIV;
                prefix[i][j] = (int) (tmp % DIV);
            }
        }

        // fill next
        int next[N][M];
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if(board[i][j] != s[c]) next[i][j] = 0;
                else{
                    int sx, sy, ex, ey;
                    long long tmp;
                    // total
                    int total = prefix[N][M];

                    // horizontal bar
                    sx = 0; sy = max(0, i-1); ex = M-1, ey = min(N-1, i+1);
                    tmp = (long long) prefix[ey+1][ex+1] +
                          (long long) prefix[sy][sx] -
                          (long long) prefix[ey+1][sx] -
                          (long long) prefix[sy][ex+1] +
                          2LL * DIV;
                    int hbar = (int) (tmp % DIV);

                    // vertical bar
                    sx = max(0, j-1); sy = 0; ex = min(M-1, j+1); ey = N-1;
                    tmp = (long long) prefix[ey+1][ex+1] +
                          (long long) prefix[sy][sx] -
                          (long long) prefix[ey+1][sx] -
                          (long long) prefix[sy][ex+1] +
                          2LL * DIV;
                    int vbar = (int) (tmp % DIV);

                    // square
                    sx = max(0, j-2); sy = max(0, i-2); ex = min(M-1, j+2); ey = min(N-1, i+2);
                    tmp = (long long) prefix[ey+1][ex+1] +
                          (long long) prefix[sy][sx] -
                          (long long) prefix[ey+1][sx] -
                          (long long) prefix[sy][ex+1] +
                          2LL * DIV;
                    int square = (int) (tmp % DIV);

                    // horizontal rectangle
                    sx = max(0, j-2); sy = max(0, i-1); ex = min(M-1, j+2); ey = min(N-1, i+1);
                    tmp = (long long) prefix[ey+1][ex+1] +
                          (long long) prefix[sy][sx] -
                          (long long) prefix[ey+1][sx] -
                          (long long) prefix[sy][ex+1] +
                          2LL * DIV;
                    int hrect = (int) (tmp % DIV);

                    // vertical rectangle
                    sx = max(0, j-1); sy = max(0, i-2); ex = min(M-1, j+1); ey = min(N-1, i+2);
                    tmp = (long long) prefix[ey+1][ex+1] +
                          (long long) prefix[sy][sx] -
                          (long long) prefix[ey+1][sx] -
                          (long long) prefix[sy][ex+1] +
                          2LL * DIV;
                    int vrect = (int) (tmp % DIV);

                    // compute sum
                    tmp = (long long) total -
                          (long long) hbar -
                          (long long) vbar -
                          (long long) square +
                          (long long) hrect +
                          (long long) vrect +
                          2LL * DIV;
                    next[i][j] = (int) (tmp % DIV);
                }
            }
        }

        // copy next to curr
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                curr[i][j] = next[i][j];
    }

    // print answer
    int ans = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            ans = (ans + curr[i][j]) % (int) DIV;
    cout << ans << '\n';
}