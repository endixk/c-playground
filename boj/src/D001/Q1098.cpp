// BOJ 1098 [Twin Villages]
// Supported by GitHub Copilot

#include <iostream>
#include <cstring>
using namespace std;

int DP[1<<20];
bool V[1<<20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int loc[N][2];
    for (int i = 0; i < N; i++) cin >> loc[i][0] >> loc[i][1];
    int P, D; cin >> P >> D;

    memset(DP, -1, sizeof(DP));
    memset(V, false, sizeof(V));
    DP[0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int dist = abs(loc[i][0] - loc[j][0]) + abs(loc[i][1] - loc[j][1]);
            if(dist < D) continue;
            for(int k = 0; k < (1 << (2*N)); k++){
                if(DP[k] == -1) continue;
                int ci = (k >> (2*i)) & 3, cj = (k >> (2*j)) & 3;
                if(ci == P || cj == P) continue;
                int nk = k | ((ci+1) << (2*i)) | ((cj+1) << (2*j));
                if(DP[nk] < 0) DP[nk] = DP[k] + dist;
                else DP[nk] = min(DP[nk], DP[k] + dist);
                V[k] = true;
            }
        }
    }

    int ans = 1e9;
    for(int i = 0; i < (1 << (2*N)); i++) if((!V[i]) && DP[i] >= 0) ans = min(ans, DP[i]);
    cout << ans;
}
