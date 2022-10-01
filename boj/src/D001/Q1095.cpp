// BOJ 1095 [Magic Crystals]
// Supported by GitHub Copilot

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool prime[100001];
vector<int> primes;

// Factorize x! into prime factors
int factor[100001];
void factorize(int x, bool add){
    for(int i : primes){
        int cnt = 0;
        for(long long j = i; j <= x; j *= i) cnt += x/(int)j;
        if(add) factor[i] += cnt;
        else factor[i] -= cnt;
    }
}

// Factorize x into prime factors
bool divisible(int x){
    for(int i : primes){
        if(i > x) break;
        int cnt = 0, pow = i;
        while(x%pow == 0){
            pow *= i;
            cnt++;
        }
        if(factor[i] < cnt) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, F, M; cin >> S >> F >> M;

    // sieve of Eratosthenes
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 100000; i++) {
        if(prime[i]) {
            for (int j = i * 2; j <= 100000; j += i) prime[j] = false;
        }
    }
    for (int i = 2; i <= 100000; i++) if(prime[i]) primes.push_back(i);

    factorize(S+F, true);
    factorize(S, false);
    factorize(F, false);

    for(int i = M; i > 0; i--){
        if(divisible(i)){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
