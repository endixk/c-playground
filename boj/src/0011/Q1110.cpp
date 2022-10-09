// BOJ 1110 [Plus Cycle]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int proc(int x){
    return (x%10)*10 + (x/10 + x%10)%10;
}
int main() {
    int N; cin >> N;
    int cycle = 0, x = N;
    while((x = proc(x)) != N) cycle++;
    cout << ++cycle;
}
