// BOJ 1091 [Shuffle the Cards]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

bool check(int N, const int P[], const int D[]) {
    for(int i = 0; i < N; i++) if(P[D[i]] != i%3) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int P[N], S[N];
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> S[i];

    int D[N], shuf = 0;
    for (int i = 0; i < N; i++) D[i] = i;
    while(!check(N, P, D)) {
        int tmp[N];
        for (int i = 0; i < N; i++) tmp[S[i]] = D[i];
        for (int i = 0; i < N; i++) D[i] = tmp[i];
        shuf++;

        // end condition
        if(shuf > 1e6) {
            shuf = -1;
            break;
        }
    }
    cout << shuf;
}
