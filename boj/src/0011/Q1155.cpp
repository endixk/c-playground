// BOJ 1155 [Modified Hanoi]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll hanoi[3][3][31];
vector<pair<int,int>> prior(6);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    for(pair<int,int>& p : prior){
        string s; cin >> s;
        p = {s[0]-'A', s[1]-'A'};
    }

    bool f0 = true, f1 = true, f2 = true;
    for(const pair<int,int>& p : prior){
        if(p.first == 0 && f0){
            hanoi[p.first][p.second][1] = 1;
            f0 = false;
        }
        else if(p.first == 1 && f1){
            hanoi[p.first][p.second][1] = 1;
            f1 = false;
        }
        else if(p.first == 2 && f2){
            hanoi[p.first][p.second][1] = 1;
            f2 = false;
        }
    }

    for(int i=2; i<=N; i++){
        for(int x=0; x<3; x++) for(int y=0; y<3; y++){
            if(x == y) continue;
            int z = 3-x-y;
            if(hanoi[x][y][i-1] && hanoi[y][x][i-1]){
                hanoi[x][y][i] = 2*hanoi[x][y][i-1] + hanoi[y][x][i-1] + 2;
            }
            if(hanoi[x][z][i-1] && hanoi[z][y][i-1]){
                hanoi[x][y][i] = hanoi[x][z][i-1] + hanoi[z][y][i-1] + 1;
            }
        }
    }

    if(hanoi[0][1][N]) cout << hanoi[0][1][N];
    else cout << hanoi[0][2][N];
}
