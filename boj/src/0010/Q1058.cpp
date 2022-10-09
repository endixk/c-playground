// BOJ 1058 [Friends]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int adj[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            adj[i][j] = c == 'Y' ? 1 : 0;
        }
    }

    int sq[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int k = 0; k < N; k++) s += adj[i][k] * adj[k][j];
            sq[i][j] = s;
        }
    }

    int MAX = 0;
    for (int i = 0; i < N; i++) {
        int f = 0;
        for (int j = 0; j < N; j++)
            if (adj[i][j] || sq[i][j]) f++;
        MAX = max(MAX, f);
    }

    if (MAX < 1) MAX = 1;
    cout << MAX - 1 << '\n';
}
