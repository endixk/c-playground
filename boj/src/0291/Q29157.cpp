#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007LL
#define MAX 2000001

vector<pair<ll, ll>> points;
vector<int> adj[25];
int N, M, K, IND[25];
ll DP[MAX];
ll FMOD[MAX];
ll FINV[MAX];
ll CASE[25];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;
    fill(DP, DP+MAX, MOD);
    DP[1] = 1; FMOD[0] = FMOD[1] = 1; FINV[0] = FINV[1] = 1;
    for(int i=2; i<MAX; i++) {
        DP[i] = -(MOD / i) * DP[MOD % i] % MOD;
        FMOD[i] = FMOD[i-1] * i % MOD;
        FINV[i] = FINV[i-1] * DP[i] % MOD;
    }

    points.emplace_back(0, 0);
    CASE[0] = 1;
    points.emplace_back(N, M);
    CASE[1] = FMOD[N+M] * FINV[N] % MOD * FINV[M] % MOD;
    for(int i=0; i<K; i++) {
        ll x, y; cin >> x >> y;
        points.emplace_back(x, y);
        CASE[i+2] = FMOD[x+y] * FINV[x] % MOD * FINV[y] % MOD;
    }

    for(int i=0; i<K+2; i++) {
        for(int j=i+1; j<K+2; j++) {
            ll x1 = points[i].first, y1 = points[i].second;
            ll x2 = points[j].first, y2 = points[j].second;
            if(x1 <= x2 && y1 <= y2) {
                adj[i].push_back(j);
                IND[j]++;
            }
            if(x1 >= x2 && y1 >= y2) {
                adj[j].push_back(i);
                IND[i]++;
            }
        }
    }

    queue<int> q;
    for(int nxt : adj[0]) {
        if(--IND[nxt] == 0) q.emplace(nxt);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ll x1 = points[cur].first, y1 = points[cur].second;
        for(int nxt : adj[cur]) {
            if(--IND[nxt] == 0) q.emplace(nxt);
            ll x2 = points[nxt].first, y2 = points[nxt].second;
            CASE[nxt] = (CASE[nxt] - CASE[cur] * FMOD[x2-x1+y2-y1] % MOD * FINV[x2-x1] % MOD * FINV[y2-y1] % MOD + MOD) % MOD;
        }
    }
    cout << (CASE[1] + MOD) % MOD << '\n';
}
