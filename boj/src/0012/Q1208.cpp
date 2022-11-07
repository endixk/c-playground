// BOJ 1208 [Subsequence Sum 2]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int arr[40], N, S;
long long cnt = 0;
vector<int> A, B;

void buildA(int i, int s){
    if(i == N/2) return;
    s += arr[i];
    A.push_back(s);
    if(s == S) cnt++;
    buildA(i+1, s);
    buildA(i+1, s-arr[i]);
}
void buildB(int i, int s){
    if(i == N) return;
    s += arr[i];
    B.push_back(s);
    if(s == S) cnt++;
    buildB(i+1, s);
    buildB(i+1, s-arr[i]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> S;
    for(int i = 0; i < N; ++i) cin >> arr[i];

    buildA(0, 0); buildB(N/2, 0);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int a : A){
        auto l = lower_bound(B.begin(), B.end(), S-a) - B.begin();
        auto r = upper_bound(B.begin(), B.end(), S-a) - B.begin();
        cnt += r-l;
    }
    cout << cnt;
}
