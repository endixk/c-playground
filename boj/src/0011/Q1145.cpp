// BOJ 1145 [Multiple of 3]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N[5]; for(int & n : N) cin >> n;
    int ans = 1e9;
    for(int i=0; i<3; i++){
        for(int j=i+1; j<4; j++){
            for(int k=j+1; k<5; k++){
                int g = gcd(N[i], N[j]);
                int l = N[i] * N[j] / g;
                g = gcd(l, N[k]);
                l = l * N[k] / g;
                ans = min(ans, l);
            }
        }
    }
    cout << ans;
}
