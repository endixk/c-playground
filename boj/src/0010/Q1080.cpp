// BOJ 1080 [Matrix]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    bool A[N][M], B[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            A[i][j] = c == '1';
        }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            B[i][j] = c == '1';
        }

    // process matrix greedily
    int cnt = 0;
    for(int i=1; i<N-1; i++)
        for(int j=1; j<M-1; j++)
            if(A[i-1][j-1]^B[i-1][j-1]){
                // flip 3x3 submatrix
                cnt++;
                for(int x=0; x<3; x++)
                    for(int y=0; y<3; y++)
                        A[i-1+x][j-1+y] = !A[i-1+x][j-1+y];
            }

    // check
    bool flag = true;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            flag &= ~(A[i][j]^B[i][j]);

    if(flag) cout << cnt;
    else cout << -1;
}
