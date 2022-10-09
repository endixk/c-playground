// BOJ 1107 [Remote Control]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

bool intact[10];
bool able(int n){
    if (n == 0) return intact[0];
    while (n) {
        if (!intact[n % 10]) return false;
        n /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for(bool & i : intact) i = true;
    for(int i = 0; i < M; i++){
        int x;
        cin >> x;
        intact[x] = false;
    }

    int ans = 1e9;
    for(int i = 0; i < 1000001; i++){
        if(i == 100) ans = min(ans, abs(N - i));
        else if(able(i)) ans = min(ans, abs(N - i) + (int) to_string(i).length());
    }
    cout << ans;
}
