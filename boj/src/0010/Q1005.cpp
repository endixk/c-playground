// ACM Craft

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;

        int *D = new int[N];
        for(int i = 0; i < N; i++)
            cin >> D[i];

        int **topo = new int*[N];
        for(int i = 0; i < N; i++) {
            topo[i] = new int[N];
            for(int j = 0; j < N; j++)
                topo[i][j] = 0;
        }
        for(int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            topo[x-1][y-1] = 1;
        }

        int W;
        cin >> W;

        // topological sort
        int *degree = new int[N];
        for(int i = 0; i < N; i++)
            degree[i] = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(topo[i][j])
                    degree[j]++;

        queue<int> q;
        for(int i = 0; i < N; i++)
            if(degree[i] == 0)
                q.push(i);

        vector<int> v;
        v.reserve(N);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            v.push_back(x);
            for(int i = 0; i < N; i++)
                if(topo[x][i])
                    if(--degree[i] == 0)
                        q.push(i);
        }

        // find the weight of W
        int *time = new int[N];
        for(int i = 0; i < N; i++)
            time[i] = 0;
        for(int x : v){
            time[x] += D[x];
            for(int j = 0; j < N; j++)
                if(topo[x][j] && time[j] < time[x])
                    time[j] = time[x];
        }

        cout << time[W-1] << endl;
    }
}