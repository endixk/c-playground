// BOJ 1102 [Power Plant]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
using namespace std;

int price[16][16];
int dp[1<<16];
vector<int> cbits[17];

int count(int bit){
    int ret = 0;
    while(bit){
        if(bit&1) ret++;
        bit >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> price[i][j];

    int mask = 0;
    for(int i=0; i<N; i++) {
        char c; cin >> c;
        if(c == 'Y') mask |= (1 << i);
    }
    int P; cin >> P;

    if(count(mask) >= P) {
        cout << 0 << endl;
        return 0;
    }

    for(int i=0; i<(1<<N); i++){
        dp[i] = -1;
        cbits[count(i)].push_back(i);
    }
    dp[mask] = 0;
    for(int i=count(mask); i<P; i++){
        for(int bit : cbits[i]){
            if(dp[bit] == -1) continue;
            for(int j=0; j<N; j++){ // turn on j
                if(bit & (1<<j)) continue;
                // get minimum price
                int mpr = 1e9;
                for(int k=0; k<N; k++) if(bit & (1<<k)) mpr = min(mpr, price[k][j]);
                // update table
                if(dp[bit | (1<<j)] == -1 || dp[bit | (1<<j)] > dp[bit] + mpr) dp[bit | (1<<j)] = dp[bit] + mpr;
            }
        }
    }

    int ans = 1e9;
    for(int bit : cbits[P]) if(dp[bit] >= 0) ans = min(ans, dp[bit]);
    if(ans == 1e9) cout << -1;
    else cout << ans;
}
