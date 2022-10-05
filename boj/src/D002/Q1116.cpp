// BOJ 1116 [Permutation II]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> cycles; // {min, min pointer}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    bool visited[N];
    for (int i = 0; i < N; i++) visited[i] = false;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;

        // find cycle
        vector<int> cycle = {i};
        int s = i, t = arr[i];
        while(t != s){
            visited[t] = true;
            cycle.push_back(t);
            t = arr[t];
        }

        // handle first cycle
        if(cycle[0] == 0) continue;

        // find min ptr
        int mp = cycle[0];
        for(;arr[mp] != cycle[0]; mp = arr[mp]);
        cycles.emplace_back(cycle[0], mp);
    }

    // find starting point
    int src = 0, dst = arr[0];
    if(!cycles.empty()) {
        int sp = cycles[0].first;
        for (auto c: cycles) if (c.first < sp) sp = c.first;
        while (dst < sp && dst != 0) {
            src = dst;
            dst = arr[dst];
        }
    }

    // reconnect cycles starting from zero
    while(!cycles.empty()){
        // find minimum starting point
        int next = cycles[0].first, ptr = cycles[0].second, idx = 0;
        for(int i = 1; i < cycles.size(); i++){
            if(cycles[i].first < next){
                next = cycles[i].first;
                ptr = cycles[i].second;
                idx = i;
            }
        }

        // reconnect
        arr[src] = next;
        src = ptr;
        cycles.erase(cycles.begin() + idx);
    }

    // reconnect last cycle
    arr[src] = dst;
    for(auto i : arr) cout << i << ' ';
}
