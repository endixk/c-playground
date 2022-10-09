// BOJ 1111 [IQ Test]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int arr[51];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // case work
    if(N == 1) cout << 'A';
    else if(N == 2){
        if(arr[0] == arr[1]) cout << arr[0];
        else cout << 'A';
    }
    else{
        int a = 0;
        if(arr[1] - arr[0] != 0) a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
        int b = arr[1] - arr[0] * a;
        bool flag = true;
        for(int i = 1; i < N; ++i){
            if(arr[i] != arr[i-1] * a + b) flag = false;
        }
        if(flag) cout << arr[N-1] * a + b;
        else cout << 'B';
    }
}
