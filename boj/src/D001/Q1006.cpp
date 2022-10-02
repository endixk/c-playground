// BOJ 1006 [Invader Chinchou]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int N, W;
int inner[10000], outer[10000];
int dp[10000][10];

void reset() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            dp[i][j] = 1e9;
        }
    }
}
void fill() {
    for(int i = 1; i < N; i++){
        bool I = inner[i] + inner[i-1] <= W, O = outer[i] + outer[i-1] <= W, H = inner[i] + outer[i] <= W;
        dp[i][0] = min(min(min(min(dp[i-1][4], dp[i-1][5]), dp[i-1][6]), dp[i-1][8]), dp[i-1][9]); // case 0
        if(I) dp[i][1] = min(dp[i-1][3], dp[i-1][7]) + 1; // case 1
        dp[i][2] = min(min(min(min(dp[i-1][4], dp[i-1][5]), dp[i-1][6]), dp[i-1][8]), dp[i-1][9]) + 1; // case 2
        if(O) dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + 1; // case 3
        if(I && O) dp[i][4] = dp[i-1][0] + 2; // case 4
        if(O) dp[i][5] = min(dp[i-1][1], dp[i-1][2]) + 2; // case 5
        if(H) dp[i][6] = min(min(min(min(dp[i-1][4], dp[i-1][5]), dp[i-1][6]), dp[i-1][8]), dp[i-1][9]) + 1; // case 6
        dp[i][7] = min(min(min(min(dp[i-1][4], dp[i-1][5]), dp[i-1][6]), dp[i-1][8]), dp[i-1][9]) + 1; // case 7
        if(I) dp[i][8] = min(dp[i-1][3], dp[i-1][7]) + 2; // case 8
        dp[i][9] = min(min(min(min(dp[i-1][4], dp[i-1][5]), dp[i-1][6]), dp[i-1][8]), dp[i-1][9]) + 2; // case 9
    }
}
int run(){
    int ans = 1e9;
    bool I = inner[0] + inner[N-1] <= W, O = outer[0] + outer[N-1] <= W, H = inner[0] + outer[0] <= W;
    // case 0
    reset(); dp[0][0] = 0; fill();
    ans = min(ans, min(min(min(min(dp[N-1][4], dp[N-1][5]), dp[N-1][6]), dp[N-1][8]), dp[N-1][9]));
    // case 1
    if(I){
        reset(); dp[0][1] = 0; fill();
        ans = min(ans, min(dp[N-1][3], dp[N-1][7]) + 1);
    }
    // case 2
    reset(); dp[0][2] = 1; fill();
    ans = min(ans, min(min(min(min(dp[N-1][4], dp[N-1][5]), dp[N-1][6]), dp[N-1][8]), dp[N-1][9]));
    // case 3
    if(O){
        reset(); dp[0][3] = 0; fill();
        ans = min(ans, min(dp[N-1][1], dp[N-1][2]) + 1);
    }
    // case 4
    if(I && O){
        reset(); dp[0][4] = 0; fill();
        ans = min(ans, dp[N-1][0] + 2);
    }
    // case 5
    if(O){
        reset(); dp[0][5] = 1; fill();
        ans = min(ans, min(dp[N-1][1], dp[N-1][2]) + 1);
    }
    // case 6
    if(H){
        reset(); dp[0][6] = 1; fill();
        ans = min(ans, min(min(min(min(dp[N-1][4], dp[N-1][5]), dp[N-1][6]), dp[N-1][8]), dp[N-1][9]));
    }
    // case 7
    reset(); dp[0][7] = 1; fill();
    ans = min(ans, min(min(min(min(dp[N-1][4], dp[N-1][5]), dp[N-1][6]), dp[N-1][8]), dp[N-1][9]));
    // case 8
    if(I){
        reset(); dp[0][8] = 1; fill();
        ans = min(ans, min(dp[N-1][3], dp[N-1][7]) + 1);
    }
    // case 9
    reset(); dp[0][9] = 2; fill();
    ans = min(ans, min(min(min(min(dp[N-1][4], dp[N-1][5]), dp[N-1][6]), dp[N-1][8]), dp[N-1][9]));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        cin >> N >> W;
        for(int i=0; i<N; i++) cin >> inner[i];
        for(int i=0; i<N; i++) cin >> outer[i];
        cout << run() << '\n';
    }
}
