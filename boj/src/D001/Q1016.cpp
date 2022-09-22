// Not-square numbers

#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main(){
    long long MIN, MAX;
    cin >> MIN >> MAX;

    bool square[1000001] = {false};
    for(int i = 2; i*i <= MAX; i++)
        if(isPrime(i))
            for(long long j = i*i; j <= MAX; j += i*i)
                if (j >= MIN)
                    square[j - MIN] = true;

    int cnt = 0;
    for(int i = 0; i <= MAX - MIN; i++)
        if(!square[i]) cnt++;

    cout << cnt << endl;
}