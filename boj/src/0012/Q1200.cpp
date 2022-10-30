// BOJ 1200 [Grid]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N, M, R, S, board[18][18];
int split[18][18];
void hsplit(int bit){
    for(int i=0, j=0; i<N; i++){
        if(i>0 && (bit&(1<<(i-1)))) j++;
        for(int k=0; k<M; k++) split[j][k] += board[i][k];
    }
}
bool check(int score){
    int buf[R+1];
    memset(buf, 0, sizeof(buf));
    for(int j=0, c=0; j<M; j++){
        bool flag = false;
        for(int i=0; i<=R; i++){
            if(buf[i] + split[i][j] > score){
                flag = true;
                break;
            }
        }
        if(flag) c++, memset(buf, 0, sizeof(buf));
        if(c > S) return false;
        for(int i=0; i<=R; i++) {
            buf[i] += split[i][j];
            if(buf[i] > score) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> R >> S;
    int tot = 0;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
        cin >> board[i][j];
        tot += board[i][j];
    }

    // find combination
    int ans = tot;
    for(int i=0; i<(1<<N); i++){
        if(bitset<18>(i).count() != R) continue;
        memset(split, 0, sizeof(split));
        hsplit(i);

        // parametric search
        int l = 0, r = tot;
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid)) r = mid-1;
            else l = mid+1;
        }
        ans = min(ans, l);
    }
    cout << ans;
}
