// BOJ 1183 [Appointments]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int N; vector<int> D;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        int a, b; cin >> a >> b;
        D.push_back(a-b);
    }

    if(N % 2) cout << 1;
    else{
        sort(D.begin(), D.end());
        cout << D[N/2] - D[N/2-1] + 1;
    }
}
