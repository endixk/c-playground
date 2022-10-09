// Cheating

#include <iostream>
#include <string>
using namespace std;

bool clean(int i){
    int l = i << 1, r = i >> 1;
    return (i & l) == 0 && (i & r) == 0;
}

bool valid(int i, int j){
    return (i & j) == 0;
}

bool pass(int i, int j){
    int l = i << 1, r = i >> 1;
    return (j & l) == 0 && (j & r) == 0;
}

int ones(int i){
    int cnt = 0;
    while(i){
        cnt += i & 1;
        i >>= 1;
    }
    return cnt;
}

int main(){
    int C;
    cin >> C;
    while(C--){
        int N, M;
        cin >> N >> M;
        int bitmax = (1 << M) - 1;

        int seat[N];
        for(int i = 0; i < N; i++) {
            string s;
            cin >> s;

            int sbit = 0;
            for(int j = s.length() - 1; j >= 0; j--){
                if(s[j] == 'x') sbit += 1;
                sbit <<= 1;
            }
            seat[i] = sbit >> 1;
        }

        // Define DP matrix
        int D[N][bitmax+1];
        for(int i = 0; i < N; i++) for(int j = 0; j <= bitmax; j++) D[i][j] = 0;

        // Initialize DP matrix
        for(int i = 0; i <= bitmax; i++){
            if(clean(i) && valid(i, seat[0])) D[0][i] = ones(i);
            else D[0][i] = 0;
        }

        // Process DP matrix
        for(int i = 1; i < N; i++){
            for(int j = 0; j <= bitmax; j++){
                D[i][j] = 0;
                if(clean(j) && valid(j, seat[i]))
                    for(int k = 0; k <= bitmax; k++)
                        if(clean(k) && pass(k, j)) D[i][j] = max(D[i][j], D[i-1][k] + ones(j));
            }
        }

        // Find max value
        int val = 0;
        for(int i = 0; i <= bitmax; i++) val = max(val, D[N-1][i]);
        cout << val << endl;
    }
}