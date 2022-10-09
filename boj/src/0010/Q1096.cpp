// BOJ 1096 [Origami]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int,bool> H, V; // possible horizontal and vertical bitmasks
void fold(const vector<vector<int>>& overlaps, map<int,bool>& M){
    for(const vector<int>& overlap : overlaps){
        int bit = 0;
        for(int v : overlap) bit |= 1 << v;
        M[bit] = true;
    }

    for(int i = 1; i < overlaps.size(); i++){ // overlapping size
        vector<vector<int>> newOverlaps;
        for(int j = i-1; j >= 0; j--){
            if(j + 2*(i-j) - 1 >= overlaps.size()) newOverlaps.push_back(overlaps[j]);
            else {
                vector<int> merged;
                for(int v : overlaps[j]) merged.push_back(v);
                for(int v : overlaps[j + 2*(i-j) - 1]) merged.push_back(v);
                newOverlaps.push_back(merged);
            }
        }
        for(int j = 2*i; j < overlaps.size(); j++) newOverlaps.push_back(overlaps[j]);
        fold(newOverlaps, M);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<int>> overlaps;
    for(int i = 0; i < N; i++) overlaps.push_back({i});
    fold(overlaps, H);
    overlaps.clear();
    for(int i = 0; i < M; i++) overlaps.push_back({i});
    fold(overlaps, V);

    int arr[N][M];
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> arr[i][j];

    int MAX = -1e5;
    for(const auto& [h, _h] : H){
        for(const auto& [v, _v] : V){
            int sum = 0;
            for(int i = 0; i < N; i++)
                for(int j = 0; j < M; j++)
                    if(h & (1 << i) && v & (1 << j)) sum += arr[i][j];
            MAX = max(MAX, sum);
        }
    }
    cout << MAX;
}
