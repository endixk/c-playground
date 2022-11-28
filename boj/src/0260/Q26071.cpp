// BOJ Contest 895-D
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1500

int N;
char board[MAX][MAX];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; ++i){
        string s; cin >> s;
        for(int j=0; j<N; ++j) board[i][j] = s[j];
    }

    bool h = false, v = false;
    int x = -1, y = -1, L=0, R=0, U=0, D=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(board[i][j] == 'G'){
                if(x == -1) x = i;
                else if(x != i) h = true;
                if(y == -1) y = j;
                else if(y != j) v = true;

                L = max(L, j);
                R = max(R, N-j-1);
                U = max(U, i);
                D = max(D, N-i-1);
            }
        }
    }

    int ans = 0;
    if(h) ans += min(U, D);
    if(v) ans += min(L, R);
    cout << ans;
}