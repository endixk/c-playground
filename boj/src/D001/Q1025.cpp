// Finding squares
// Supported by GitHub Copilot

#include <iostream>
#include <cmath>
using namespace std;

bool isSquare(int n) {
    return int(sqrt(n)) * int(sqrt(n)) == n;
}

int main(){
    int N, M;
    cin >> N >> M;

    int arr[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    int MAX = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            // starting point: (i, j)
            if(isSquare(arr[i][j])) MAX = max(MAX, arr[i][j]);
            for(int ly=-i; ly<N-i; ly++){ // y-axis leap factor
                for(int lx=-j; lx<M-j; lx++){ // x-axis leap factor
                    if(ly == 0 && lx == 0) continue;
                    int make = 0;
                    int x = 0, y = 0;
                    while(i+y < N && j+x < M && i+y >= 0 && j+x >= 0){
                        make = make * 10 + arr[i+y][j+x];
                        if(isSquare(make)){
                            MAX = max(MAX, make);
                        }
                        x += lx;
                        y += ly;
                    }
                }
            }
        }
    }

    cout << MAX << endl;
}