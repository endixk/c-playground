// BOJ 2438 [Printing Stars 1]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    char s[100]; fill(s, s+100, '*');
    for(int i=1; i<=N; i++) s[i] = 0, puts(s), s[i] = '*';
}
