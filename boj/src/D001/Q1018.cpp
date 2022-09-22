// Chessboard painting
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    // import board
    bool board[N][M];
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            if(s[j] == 'W') board[i][j] = true;
            else board[i][j] = false;
        }
    }

    // scan board
    int cnt = 64;
    for(int i = 0; i < N-7; i++){
        for(int j = 0; j < M-7; j++){
            int wb = 0, bw = 0;
            for(int x = 0; x < 8; x++){
                for(int y = 0; y < 8; y++){
                    if(x%2){
                        if(y%2){
                            if(board[i+x][j+y]) wb++;
                            else bw++;
                        }
                        else{
                            if(board[i+x][j+y]) bw++;
                            else wb++;
                        }
                    }
                    else{
                        if(y%2){
                            if(board[i+x][j+y]) bw++;
                            else wb++;
                        }
                        else{
                            if(board[i+x][j+y]) wb++;
                            else bw++;
                        }
                    }
                }
            }
            if(wb < cnt) cnt = wb;
            if(bw < cnt) cnt = bw;
        }
    }

    cout << cnt << endl;
}