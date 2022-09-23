// Divisors
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N; cin >> N;
    int div[N];
    for(int i = 0; i < N; i++) cin >> div[i];
    sort(div, div + N);
    cout << div[0] * div[N - 1] << endl;
}