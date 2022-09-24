// Decresing numbers
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;

    int d[11][10];
    for(int s = 0; s < 10; s++) d[0][s] = 0;
    for(int s = 0; s < 10; s++) d[1][s] = 1;
    for(int n = 2; n < 11; n++){
        for(int s = 0; s < 10; s++){
            if(n > s + 1) d[n][s] = 0;
            else{
                d[n][s] = 0;
                for(int k = 0; k < s; k++) d[n][s] += d[n-1][k];
            }
        }
    }
    int acc = 0, pn = -1, ps = -1, rank = -1;
    for(int n = 0; n < 11; n++){
        int row = 0;
        for(int s = 0; s < 10; s++){
            if(acc + row + d[n][s] > N){
                pn = n;
                ps = s;
                rank = N - acc + 1;
                break;
            }
            row += d[n][s];
        }
        if(pn != -1) break;
        acc += row;
    }

    if(pn < 0) cout << -1 << endl;
    while(pn > 0){
        for(int s = 0; s <= ps; s++){
            if(rank > d[pn][s]){
                rank -= d[pn][s];
            }else{
                cout << s;
                pn--;
                ps = s-1;
                break;
            }
        }
    }
    return 0;
}