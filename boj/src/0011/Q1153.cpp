// BOJ 1153 [Four Primes]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    for(int i=2; i*i<=n; i++)
        if(n%i == 0) return false;
    return true;
}

// split even number to two primes
void goldbach(int x){
    for(int p=2; p<=x/2; p++){
        if(prime(p) && prime(x-p)){
            cout << p << ' ' << x-p;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    if(N < 8) cout << -1;
    else if(N % 2){
        cout << 2 << ' ' << 3 << ' ';
        goldbach(N-5);
    }
    else{
        cout << 2 << ' ' << 2 << ' ';
        goldbach(N-4);
    }
}
