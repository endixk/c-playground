// BOJ 1184 [Back to Farming]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N, A[51][51], P[51][51];
void prefix(){
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            P[i+1][j+1] = A[i][j] + P[i+1][j] + P[i][j+1] - P[i][j];
        }
    }
}
int presum(int x1, int y1, int x2, int y2){
    return P[x2+1][y2+1] - P[x2+1][y1] - P[x1][y2+1] + P[x1][y1];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> A[i][j];
    }
    prefix();

    int cnt = 0;
    for(int x=1; x<N; x++){
        for(int y=1; y<N; y++){
            // upper-left vs. lower-right
            map<int,int> m;
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++) m[presum(i,j,x-1,y-1)]++;
            }
            for(int i=x; i<N; i++){
                for(int j=y; j<N; j++) cnt += m[presum(x,y,i,j)];
            }
            // lower-left vs. upper-right
            m.clear();
            for(int i=x; i<N; i++){
                for(int j=0; j<y; j++) m[presum(x,j,i,y-1)]++;
            }
            for(int i=0; i<x; i++){
                for(int j=y; j<N; j++) cnt += m[presum(i,y,x-1,j)];
            }
        }
    }
    cout << cnt;
}
