// BOJ 1139 [Fence]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> valid(int bit){
    vector<int> ret;
    for(int i=0; i<N; i++) if(!(bit & (1<<i))) ret.push_back(i);
    return ret;
}

bool triangle(int x, int y, int z){
    return x+y > z && x+z > y && y+z > x;
}

double area(int x, int y, int z){
    double s = (x+y+z)/2.0;
    return sqrt(s*(s-x)*(s-y)*(s-z));
}

double dp[1<<16];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int len[N];
    for(int i=0; i<N; i++) cin >> len[i];

    fill(dp, dp+(1<<N), -1.0);
    dp[0] = .0;
    double ans = .0;
    for(int i=0; i<N/3; i++){
        vector<int> visit;
        for(int bit = 0; bit < (1<<N); bit++) if(dp[bit] != -1.0) visit.push_back(bit);
        for(int bit : visit){
            vector<int> v = valid(bit);
            for(int x=0; x<v.size()-2; x++){
                for(int y=x+1; y<v.size()-1; y++){
                    for(int z=y+1; z<v.size(); z++){
                        int X = len[v[x]], Y = len[v[y]], Z = len[v[z]];
                        if(triangle(X, Y, Z)){
                            int nbit = bit | (1<<v[x]) | (1<<v[y]) | (1<<v[z]);
                            dp[nbit] = max(dp[nbit], dp[bit] + area(X, Y, Z));
                            ans = max(ans, dp[nbit]);
                        }
                    }
                }
            }
            dp[bit] = -1.0;
        }
    }

    cout << fixed << setprecision(15) << (ans > 0 ? ans : 0.0);
}
