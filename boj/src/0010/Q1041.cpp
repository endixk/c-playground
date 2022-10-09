// BOJ 1041 [Dice]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    long long ones[6] = {A, B, C, D, E, F};
    long long twos[12] = {A + B, A + C, A + D, A + E, B + C, B + D, B + F, C + E, C + F, D + E, D + F, E + F};
    long long thrs[8] = {A + B + C, A + B + D, A + C + E, A + D + E, B + C + F, B + D + F, C + E + F, D + E + F};

    if(N == 1){
        long long max1 = 0, sum1 = 0;
        for (long long &one: ones){
            max1 = max(max1, one);
            sum1 += one;
        }
        cout << sum1 - max1 << endl;
        return 0;
    }

    long long min1 = 50, min2 = 100, min3 = 150;
    for (long long &one: ones) min1 = min(min1, one);
    for (long long &two: twos) min2 = min(min2, two);
    for (long long &thr: thrs) min3 = min(min3, thr);

    cout << min1 * (5 * N * N - 16 * N + 12) + min2 * (8 * N - 12) + min3 * 4 << endl;
}