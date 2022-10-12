// BOJ 1147 [Rhombus]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct vec{
    int x, y, size;
    vec(int x, int y) : x(x), y(y) {size = x*x + y*y;}
    bool operator<(const vec& v) const { return size < v.size; }
};

int N, M, cnt = 0;
priority_queue<vec> pq;
void solve(int p, int q){
    for(int j = q+1; j <= M; j++) pq.push({0, j-q});
    for(int i = p+1; i <= N; i++)
        for(int j=0; j <= M; j++) pq.push({i-p, j-q});
    while(!pq.empty()) {
        vector<vec> v = {pq.top()}; pq.pop();
        while(!pq.empty() && pq.top().size == v[0].size) {
            v.push_back(pq.top()); pq.pop();
        }
        if(v.size() == 1) continue;
        for(int i = 0; i < v.size(); i++)
            for(int j = i+1; j < v.size(); j++)
                if(v[i].x + v[j].x + p <= N && v[i].y + v[j].y + q <= M) cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= M; j++) solve(i, j);
    cout << cnt;
}
