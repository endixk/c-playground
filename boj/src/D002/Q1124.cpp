// BOJ 1124 [Under-prime]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

// sieve of eratosthenes
bool prime[100001];
vector<int> primes;
void sieve(){
    for(int i=2; i<=100000; i++) prime[i] = true;
    for(int i=2; i<=100000; i++){
        if(!prime[i]) continue;
        for(int j=i+i; j<=100000; j+=i) prime[j] = false;
    }
    for(int i=2; i<=100000; i++) if(prime[i]) primes.push_back(i);
}

int nprime(int n){
    int cnt = 0;
    for(int p : primes){
        if(p > n) break;
        while(n % p == 0){
            n /= p;
            cnt++;
        }
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B; cin >> A >> B;
    sieve();
    int cnt = 0;
    for(int n=A; n<=B; n++) if(prime[nprime(n)]) cnt++;
    cout << cnt;
}
