// BOJ 1101 [Organizing Cards]
// Supported by GitHub Copilot

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int box[N][M];
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> box[i][j];

    int ans = N;
    for(int i = 0; i < N; i++){
        bool dup[M]; memset(dup, false, sizeof(dup));
        int cnt = 0; // minimum boxes to move
        for(int j = 0; j < N; j++){
            if(i == j) continue; // box is a joker
            int col = 0, loc = -1; // number of color types
            for(int k = 0; k < M; k++){
                if(box[j][k] != 0){
                    col++;
                    loc = k;
                }
            }
            if(col == 1){
                if(dup[loc]) cnt++;
                else dup[loc] = true;
            }
            if(col > 1) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans;
}
