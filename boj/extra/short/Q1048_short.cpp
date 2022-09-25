#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll DIV = 1000000007;

ll P[301][301];int N,M;
ll g(int a,int b,int c,int d){
    a=max(a,0);b=max(b,0);c=min(c,N-1);d=min(d,M-1);
    return (P[d+1][c+1]+P[b][a]-P[d+1][a]-P[b][c+1]+2*DIV)%DIV;
}
int main() {
    int L; cin >> N >> M >> L;
    string s; cin >> s;

    string board[N];
    for (int i=0; i<N; i++) cin >> board[i];

    ll curr[N][M];
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            curr[i][j] = (board[i][j] == s[0] ? 1 : 0);

    for (int c=1; c<s.length(); c++){
        // prefix sum
        for(int i=0; i<=N; i++)for(int j=0; j<=M; j++)P[i][j]=0;
        for(int i=1; i<=N; i++)for(int j=1; j<=M; j++)P[i][j]=(curr[i-1][j-1]+P[i-1][j]+P[i][j-1]-P[i-1][j-1]+DIV)%DIV;
        ll next[N][M];
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if(board[i][j] != s[c]) next[i][j] = 0;
                else next[i][j] = (P[N][M]-g(0,i-1,M-1,i+1)-g(j-1,0,j+1,N-1)-g(j-2,i-2,j+2,i+2)+g(j-2,i-1,j+2,i+1)+g(j-1,i-2,j+1,i+2)+3*DIV)%DIV;
            }
        }
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                curr[i][j] = next[i][j];
    }

    // print answer
    int ans = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            ans = (ans + (int)curr[i][j]) % (int)DIV;
    cout << ans << '\n';
}