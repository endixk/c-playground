// BOJ 11478 [Distinct Substrings]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
string S;

// compute suffix array with Manber-Myers algorithm
int SA[MAX], tmp[MAX], g[MAX], idx;
bool cmp(int a, int b) {
    if (g[a] != g[b]) return g[a] < g[b];
    return g[a + idx] < g[b + idx];
}
void buildSA() {
    int n = (int)S.size();
    for (int i = 0; i < n; i++) {
        SA[i] = i;
        g[i] = S[i] - 'a';
    }
    g[n] = -1;
    for (idx = 1; idx < n; idx *= 2) {
        sort(SA, SA + n, cmp);
        tmp[SA[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[SA[i]] = tmp[SA[i - 1]] + cmp(SA[i - 1], SA[i]);
        }
        for (int i = 0; i < n; i++) {
            g[i] = tmp[i];
        }
    }
}

// compute LCP array with Kasai algorithm
int LCP[MAX];
void buildLCP() {
    int n = (int)S.size();
    for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
        if (g[i] == n - 1) continue;
        for (int j = SA[g[i] + 1]; S[i + k] == S[j + k]; k++);
        LCP[g[i]] = k;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> S;
    buildSA(), buildLCP();
    int ans = 0, n = (int)S.size();
    for(int i=0; i<n; i++) ans += n - SA[i] - LCP[i];
    cout << ans;
}
