// BOJ 1115 [Permutation]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    int cycle = 0;
    bool visited[N];
    for (int i = 0; i < N; i++) visited[i] = false;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        int s = i, t = arr[i];
        while(t != s){
            visited[t] = true;
            t = arr[t];
        }
        cycle++;
    }

    if(cycle == 1) cout << 0;
    else cout << cycle;
}
