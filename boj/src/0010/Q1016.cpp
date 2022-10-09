// Not-square numbers

#include <iostream>
using namespace std;

int main(){
    long long MIN, MAX;
    cin >> MIN >> MAX;

    bool square[1000001];
    bool prime[1000001];
    for (int i = 0; i <= 1000000; i++) {
        square[i] = false;
        if(i % 2 == 0) prime[i] = false;
        else prime[i] = true;
    }
    prime[1] = false;
    prime[2] = true;
    for(int i = 3; i <= 1000000; i++){
        if(!prime[i]) continue;
        for(int j = i*3; j <= 1000000; j += i*2){
            prime[j] = false;
        }
    }

    for(long long i = 2; i <= 1000000; i++)
        if(prime[i]) {
            long long sq = i*i;
            for (long long j = MIN - (MIN % sq); j <= MAX; j += sq)
                if(j >= MIN)
                    square[j - MIN] = true;
        }
    int cnt = 0;
    for(int i = 0; i <= MAX - MIN; i++)
        if(!square[i]) cnt++;

    cout << cnt << endl;
}