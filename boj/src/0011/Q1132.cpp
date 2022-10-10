// BOJ 1132 [Sum]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<string> v(N);
    int maxL = 0;
    for(int i=0; i<N; ++i) cin >> v[i], maxL = max(maxL, (int)v[i].size());

    int cnt[10][maxL];
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<N; ++i) {
        int len = (int)v[i].size();
        for(int j=0; j<len; ++j) {
            cnt[v[i][j]-'A'][len-j-1]++;
        }
    }

    ll value[10]; int assign[10];
    memset(value, 0, sizeof(value));
    memset(assign, -1, sizeof(assign));

    // calculate value
    for(int i=0; i<10; ++i)
        for(int j=0; j<maxL; ++j)
            value[i] += (ll)cnt[i][j] * (ll)pow(10, j);

    // assign value
    for(int i=0; i<10; ++i){
        ll minv = 0, mini = -1;
        for(int j=0; j<10; ++j) {
            if(i == 0){
                bool flag = true;
                for(string s : v) if(s[0] == j+'A') flag = false;
                if(!flag) continue;
            }
            if(assign[j] != -1) continue;
            if(mini == -1 || minv > value[j]) {
                minv = value[j];
                mini = j;
            }
        }
        assign[mini] = i;
    }

    // calculate answer
    ll ans = 0;
    for(int i=0; i<10; ++i)
        ans += value[i] * (ll)assign[i];
    cout << ans;
}