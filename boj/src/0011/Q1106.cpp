// BOJ 1106 [Hotel]
// Supported by GitHub Copilot

#include <iostream>
#include <cstring>
using namespace std;

int dp[100001], price[21], value[21];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N; cin >> C >> N;
    for (int i = 0; i < N; i++) cin >> price[i] >> value[i];

    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 100001; i++){
        for(int j = 0; j < N; j++){
            if(i + price[j] <= 100000) dp[i + price[j]] = max(dp[i + price[j]], dp[i] + value[j]);
        }
    }

    for(int i = 0; i < 100001; i++){
        if(dp[i] >= C){
            cout << i;
            return 0;
        }
    }
}
