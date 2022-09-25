// BOJ 1051 [Number square]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int arr[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &arr[i][j]);

    int MAX = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int k = 1;
            while (i + k < N && j + k < M) {
                if (arr[i][j] == arr[i][j + k] &&
                    arr[i][j] == arr[i + k][j] &&
                    arr[i][j] == arr[i + k][j + k])
                    MAX = max(MAX, (k + 1) * (k + 1));
                k++;
            }
        }
    }

    cout << MAX << '\n';
}
