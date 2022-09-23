// Art exchange
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int ones(int n) {
    int ret = 0;
    while (n) {
        if (n % 2) ret++;
        n /= 2;
    }
    return ret;
}

int main(){
    int N;
    cin >> N;

    int call[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &call[i][j]);
        }
    }

    bool dp[1 << N][N][10];
    for(int i=0; i<(1 << N); i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<10; k++){
                dp[i][j][k] = false;
            }
        }
    }

    int MAX = 0;
    dp[1][0][0] = true;
    for(int state = 0; state < (1 << N); state++){
        for(int owner = 0; owner < N; owner++){
            for(int price = 0; price < 10; price++){
                if(!dp[state][owner][price]) continue;
                MAX = max(MAX, ones(state));

                if(state & (1 << owner)){
                    for(int buyer = 0; buyer < N; buyer++){
                        if(state & (1 << buyer)) continue;
                        if(call[owner][buyer] < price) continue;
                        dp[state | (1 << buyer)][buyer][call[owner][buyer]] = true;
                    }
                }
            }
        }
    }

    cout << MAX << endl;
}