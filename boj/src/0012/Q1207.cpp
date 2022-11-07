// BOJ 1207 [Cutting Paper]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int L;
bool pieces[5][10][10];
int board[10][10], offset[5];
bool check(){
    for(int i=0; i<L; i++)
        for(int j=0; j<L; j++)
            if(!board[i][j]) return false;
    return true;
}
bool place(int p){
    // find top-left most position
    int x, y;
    for(x=0; x<L; x++) {
        bool flag = false;
        for(y=0; y<L; y++) {
            if(!board[x][y]) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    y -= offset[p];
    if(y < 0) return false;

    for(int px=0; px<L; px++) for(int py=0; py<L; py++){
        if(pieces[p][px][py]){
            if(x+px >= L || y+py >= L) return false;
            if(board[x+px][y+py]) return false;
            board[x+px][y+py] = p+1;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> L;
    for(int i=0; i<5; i++){
        int x, y; cin >> x >> y;
        for(int j=0; j<x; j++) {
            string s; cin >> s;
            for(int k=0; k<y; k++) {
                pieces[i][j][k] = s[k] == '#';
            }
        }
        while(!pieces[i][0][offset[i]]) offset[i]++;
    }

    int perm[5] = {0, 1, 2, 3, 4};
    do{
        memset(board, 0, sizeof(board));
        bool ok = true;
        for(int p : perm) if(!place(p)) {
            ok = false;
            break;
        }
        if(ok && check()){
            for(int i=0; i<L; i++){
                for(int j=0; j<L; j++) cout << board[i][j];
                cout << '\n';
            }
            return 0;
        }
    } while(next_permutation(perm, perm+5));
    cout << "gg";
}
