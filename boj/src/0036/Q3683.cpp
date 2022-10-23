// BOJ 3683 [Cats and Dogs]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 501

vector<int> graph[MAX];
int match[MAX];
bool visited[MAX];

void reset(){
    for(auto &v: graph) v.clear();
    memset(match, 0, sizeof(match));
}

// bipartite matching
bool dfs(int u){
    for(int v: graph[u]){
        if(visited[v]) continue;
        visited[v] = true;
        if(match[v] == 0 || dfs(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        reset();
        int c, d, v; cin >> c >> d >> v;
        vector<pair<int,int>> cv, dv; // cat lovers, dog lovers
        for(int i=0; i<v; i++){
            string acc, rej; cin >> acc >> rej;
            int a = stoi(acc.substr(1)), r = stoi(rej.substr(1));
            if(acc[0] == 'C') cv.emplace_back(a, r);
            else dv.emplace_back(a, r);
        }

        // build graph
        for(int i=0; i<(int)cv.size(); i++){
            for(int j=0; j<(int)dv.size(); j++){
                if(cv[i].first == dv[j].second || cv[i].second == dv[j].first) graph[i+1].push_back(j+1);
            }
        }

        // bipartite matching
        int ans = 0;
        for(int i=1; i<=(int)cv.size(); i++){
            memset(visited, false, sizeof(visited));
            ans += dfs(i);
        }
        cout << v - ans << '\n';
    }
}
