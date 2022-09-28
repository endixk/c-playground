// BOJ 1007 [Vector Matching]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
double MIN = 1e9;
vector<pair<int, int>> coord;
void perm(int mask, int ptr, int depth){
    if(depth == N/2){
        long long sx = 0, sy = 0;
        for(int i = 0; i < N; i++){
            if(mask & (1 << i)){
                sx += coord[i].first;
                sy += coord[i].second;
            }
            else{
                sx -= coord[i].first;
                sy -= coord[i].second;
            }
        }
        MIN = min(MIN, sqrt(sx*sx + sy*sy));
    }
    for(int i=ptr; i<N; i++)
        perm(mask | (1<<i), i+1, depth+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    cout.precision(15);
    while(T--){
        cin >> N;
        coord.resize(N);
        for(int i=0; i<N; i++) cin >> coord[i].first >> coord[i].second;

        MIN = 1e9;
        perm(0, 1, 0);
        cout << MIN << '\n';
    }

}
