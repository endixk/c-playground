// BOJ 1120 [String]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

int dist(const string& x, const string& y){
    if(x.length() != y.length()) return -1;
    int ret = 0;
    for(int i=0; i<x.length(); i++) if(x[i] != y[i]) ret++;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int d = 50;
    for(int i=0; i<=B.length()-A.length(); i++) d = min(d, dist(A, B.substr(i, A.length())));
    cout << d;
}
