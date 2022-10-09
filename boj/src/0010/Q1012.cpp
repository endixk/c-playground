// Organic lettuce

#include <iostream>
#include <queue>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        int M, N, K;
        cin >> M >> N >> K;

        bool barn[50][50] = {false, };
        for (int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            barn[x][y] = true;
        }

        int cnt = 0;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (barn[i][j]){
                    cnt++;
                    queue<pair<int, int>> q;
                    barn[i][j] = false;
                    q.push({i, j});

                    while (!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if(x > 0 && barn[x-1][y])
                            q.push({x-1, y}), barn[x-1][y] = false;
                        if(x < M-1 && barn[x+1][y])
                            q.push({x+1, y}), barn[x+1][y] = false;
                        if(y > 0 && barn[x][y-1])
                            q.push({x, y-1}), barn[x][y-1] = false;
                        if(y < N-1 && barn[x][y+1])
                            q.push({x, y+1}), barn[x][y+1] = false;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}