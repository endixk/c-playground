// BOJ 1147 [Rhombus]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct vec{
    int x, y, size;
    vec(int x, int y) : x(x), y(y) {size = x*x + y*y;}
    bool operator<(const vec& rhs) const { return size < rhs.size; }
    int operator*(const vec &rhs) const { return x*rhs.x + y*rhs.y; }
};
bool para(const vec &a, const vec &b) {
    return (a*b)*(a*b) == (a*a)*(b*b);
}

int N, M, cnt = 0;
priority_queue<vec> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for(int i=-N; i<=N; i++)
        for(int j=-M; j<=M; j++)
            if(i || j) pq.push(vec(i, j));

    while(!pq.empty()){
        vector<vec> v;
        int size = pq.top().size;
        while(!pq.empty() && pq.top().size == size){
            v.push_back(pq.top());
            pq.pop();
        }
        for(int i=0; i<v.size(); i++)
            for(int j=0; j<v.size(); j++){
                if(i == j) continue;
                if(para(v[i], v[j])) continue;

                int x1 = 0, y1 = 0;
                int x2 = v[i].x, y2 = v[i].y;
                int x3 = v[j].x, y3 = v[j].y;
                int x4 = x2 + x3, y4 = y2 + y3;
                int xs = max({x1, x2, x3, x4}) - min({x1, x2, x3, x4});
                int ys = max({y1, y2, y3, y4}) - min({y1, y2, y3, y4});
                if(xs >= 0 && xs <= N && ys >= 0 && ys <= M)
                    cnt += (N - xs + 1) * (M - ys + 1);
            }

    }
    cout << cnt / 8;
}
