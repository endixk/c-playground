// BOJ 1073 [Domino]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> adj[10];

    // generate undirected graph from dominos
    for(int i = 0; i < N; i++){
        char a, b; cin >> a >> b;
        adj[a-'0'].push_back(b-'0');
        adj[b-'0'].push_back(a-'0');
    }

    // record the numbers of available pairs with dp
    long long dp[9];
    dp[0] = 0; dp[2] = 1;
    for(int i = 4; i < 9; i+=2) dp[i] = dp[i-2] * (i-1);

    // calculate the number of cycles
    long long ans = 1;
    for(auto & vec : adj){
        if(vec.empty()) continue;
        if(vec.size() % 2 == 1) ans *= 0;
        else ans *= dp[vec.size()];
    }

    cout << ans;
}
