// BOJ 2610 [Meeting Preparation]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 0x3f3f3f3f

vector<int> adj[MAX];
int cc[MAX], cmn[MAX], cmi[MAX];
bool vis[MAX];
void dfs(int u, int i) {
    cc[u] = i;
    for (int v : adj[u]) if (!cc[v]) dfs(v, i);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;

    for (int i=0; i<m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ci = 0;
    for (int i=1; i<=n; i++) {
        if (!cc[i]) dfs(i, ++ci);
    }

    memset(cmn, 0x3f, sizeof(cmn));
    for (int i=1; i<=n; ++i) {
        memset(vis, false, sizeof(vis));
        queue<int> q;
        q.push(i); vis[i] = true; int d = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) if (!vis[v]) {
                    q.push(v); vis[v] = true;
                }
            }
            ++d;
        }
        if (d < cmn[cc[i]]) {
            cmn[cc[i]] = d;
            cmi[cc[i]] = i;
        }
    }
    sort(cmi+1, cmi+ci+1);

    cout << ci << '\n';
    for (int i=1; i<=ci; ++i) cout << cmi[i] << '\n';
}
