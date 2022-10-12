// BOJ 1138 [Line up]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    int arr[N], res[N];
    for (int i=0; i<N; i++) cin >> arr[i];
    memset(res, 0, sizeof(arr));

    for(int i=0; i<N; i++){
        int loc = 0;
        for(int j=0; j<N; j++){
            if(res[j] == 0){
                if(loc++ == arr[i]){
                    res[j] = i+1;
                    break;
                }
            }
        }
    }

    for(int i=0; i<N; i++) cout << res[i] << ' ';
}
