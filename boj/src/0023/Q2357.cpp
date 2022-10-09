// BOJ 2357 [Minimum and Maximum]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int arr[1<<17], maxseg[1<<18], minseg[1<<18];

// build max segment tree
int build_max(int n, int s, int e){
    if(s == e) return maxseg[n] = arr[s];
    int m = (s+e)/2;
    return maxseg[n] = max(build_max(n*2, s, m), build_max(n*2+1, m+1, e));
}

// build min segment tree
int build_min(int n, int s, int e){
    if(s == e) return minseg[n] = arr[s];
    int m = (s+e)/2;
    return minseg[n] = min(build_min(n*2, s, m), build_min(n*2+1, m+1, e));
}

// query max segment tree
int query_max(int n, int s, int e, int l, int r){
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return maxseg[n];
    int m = (s+e)/2;
    return max(query_max(n*2, s, m, l, r), query_max(n*2+1, m+1, e, l, r));
}

// query min segment tree
int query_min(int n, int s, int e, int l, int r){
    if(r < s || e < l) return 1e9;
    if(l <= s && e <= r) return minseg[n];
    int m = (s+e)/2;
    return min(query_min(n*2, s, m, l, r), query_min(n*2+1, m+1, e, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> arr[i];
    build_max(1, 1, N);
    build_min(1, 1, N);
    while(M--){
        int a, b; cin >> a >> b;
        cout << query_min(1, 1, N, a, b) << ' ' << query_max(1, 1, N, a, b) << '\n';
    }
}
