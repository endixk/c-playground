// BOJ 13974 [Merging Files 2]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 5001
#define INF 0x3f3f3f3f

int A[MAX], S[MAX], D[MAX][MAX], K[MAX][MAX];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i=1; i<=N; ++i) cin >> A[i], S[i] = S[i-1] + A[i];
        for(int i=1; i<=N; ++i) D[i-1][i] = 0, K[i-1][i] = i;
        for(int x=2; x<=N; ++x){
            for(int i=0; i+x<=N; ++i){
                int j = i+x;
                D[i][j] = INF;
                for(int k=K[i][j-1]; k<=K[i+1][j]; ++k){
                    int tmp = D[i][k] + D[k][j] + S[j] - S[i];
                    if(D[i][j] > tmp) D[i][j] = tmp, K[i][j] = k;
                }
            }
        }
        cout << D[0][N] << '\n';
    }
}
