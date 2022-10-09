// Bridge

#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;

        int D[30][30] = {0};
        for(int i = M-1; i >= 0; i--)
            D[N-1][i] = M-i;
        for(int i = N-2; i >= 0; i--)
            for(int j = M-1; j >= 0; j--)
                for(int k = M-1; k > j; k--)
                    D[i][j] += D[i+1][k];

        cout << D[0][0] << endl;
    }
}