// BOJ 1081 [Sum]
// Supported by GitHub Copilot
// code imported from the solution for Q1019

#include <iostream>
using namespace std;
typedef long long ll;

ll count(ll N, int digit){
    ll count = 0;
    ll factor = 1;
    while(N / factor > 0){
        ll curr = (N / factor) % 10;
        ll prev = N / (factor * 10);
        ll next = N - (N / factor) * factor;

        if(curr > digit) count += (prev + 1) * factor;
        else if(curr == digit) count += prev * factor + next + 1;
        else count += prev * factor;

        factor *= 10;
    }
    return count;
}

ll digitsum(int N){
    ll sum = 0;
    for(int digit = 0; digit < 10; digit++){
        sum += digit * count(N, digit);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll L, U; cin >> L >> U;
    cout << digitsum(U) - digitsum(L - 1) << '\n';
}
