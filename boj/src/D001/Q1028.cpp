// Diamond mine
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main(){
    int R, C;
    cin >> R >> C;

    bool map[R][C];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char c;
            cin >> c;
            map[i][j] = c == '1';
        }
    }

    int ur[R][C], ul[R][C];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            ur[i][j] = ul[i][j] = 0;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j]){
                ur[i][j] = ul[i][j] = 1;
                if(i > 0 && j < C-1) ur[i][j] += ur[i-1][j+1];
                if(i > 0 && j > 0) ul[i][j] += ul[i-1][j-1];
            }
        }
    }

    int MAX = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j]){
                int k = 1;
                MAX = max(MAX, k);
                while(i-k >= 0 && j-k >= 0 && j+k < C){
                    if(!map[i-k][j-k] || !map[i-k][j+k]) break;
                    if(ur[i-k][j-k] > k && ul[i-k][j+k] > k)
                        MAX = max(MAX, k+1);
                    k++;
                }
            }
        }
    }

    cout << MAX << endl;
}