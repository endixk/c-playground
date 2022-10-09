// BOJ 1122 [Flip]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll A, B, K; cin >> A >> B >> K;
    if(A == 0){
        cout << 0;
        return 0;
    }
    for(ll N = 1; N <= A+B; N++){
        if(A <= N*K && N*K <= (2*((N-1)/2)+1)*A + 2*(N/2)*B){
            if(N*K % 2 == A % 2) {
                cout << N;
                return 0;
            }
        }
    }
    cout << -1;
}
