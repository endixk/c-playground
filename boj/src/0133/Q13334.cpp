// BOJ 13334 [Railroad]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct Line{
    int s, e;
    Line (int s, int e) : s(s), e(e) {}
    bool operator<(const Line &l) const {
        return e < l.e;
    }
};

struct cmp{
    bool operator()(const Line &l1, const Line &l2) const {
        return l1.s > l2.s;
    }
};

priority_queue<Line, vector<Line>, cmp> PQ;
vector<Line> lines;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int s, e; cin >> s >> e;
        if (s > e) swap(s, e);
        lines.emplace_back(s, e);
    }
    int D; cin >> D;
    sort(lines.begin(), lines.end());

    int ans = 0;
    for(auto &l : lines){
        PQ.push(l);
        while(!PQ.empty() && l.e - D > PQ.top().s) PQ.pop();
        ans = max(ans, (int)PQ.size());
    }
    cout << ans;
}
