// BOJ 1154 [Team Organization]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<int> graph[MAX];
int group[MAX], cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    int u, v; cin >> u >> v;
    while(u > 0 && v > 0) {
        graph[u].push_back(v);
        graph[v].push_back(u);
        cin >> u >> v;
    }

    for(int i=1; i<=N; i++){
        bool fr[N+1];
        memset(fr, false, sizeof(fr));
        fr[i] = true;
        for(int x : graph[i]) fr[x] = true;

        vector<int> nf;
        for(int j=1; j<=N; j++) if(!fr[j]) nf.push_back(j);
        if(nf.empty()) continue;

        int grp = MAX;
        for(int x : nf) if(group[x]) grp = min(grp, group[x]);
        if(grp == MAX) grp = ++cnt;
        for(int x : nf) group[x] = grp;
    }

    if(cnt == 2){
        vector<int> g1, g2;
        for(int i=1; i<=N; i++){
            if(group[i] == 1) g1.push_back(i);
            else g2.push_back(i);
        }

        sort(g1.begin(), g1.end());
        sort(g2.begin(), g2.end());
        if(g2[0] == 1) swap(g1, g2);

        cout << 1 << '\n';
        for(int x : g1) cout << x << ' ';
        cout << -1 << '\n';
        for(int x : g2) cout << x << ' ';
        cout << -1;
    }
    else if(cnt == 0){
        cout << 1 << '\n';
        cout << 1 << ' ' << -1 << '\n';
        for(int i=2; i<=N; i++) cout << i << ' ';
        cout << -1;
    }
    else cout << -1;
}
