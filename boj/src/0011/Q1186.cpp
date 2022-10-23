// BOJ 1186 [Coloring Rectangles]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int N, K;
int xs[51], ys[51], xe[51], ye[51], area[51];
int xmax = -MAX, xmin = MAX, ymax = -MAX, ymin = MAX;
bool on[51];

void sweep(int x){
    vector<tuple<int,int,bool>> marks;
    for(int i=1; i<=N; i++){
        if(xs[i] <= x && x < xe[i]){
            marks.emplace_back(ys[i], i, true);
            marks.emplace_back(ye[i], i, false);
        }
    }
    sort(marks.begin(), marks.end());

    int top = 0, py = ymin;
    for(auto mark : marks){
        int y, k; bool b;
        tie(y, k, b) = mark;
        area[top] += y - py;
        if(b){
            on[k] = true;
            if(k > top) top = k;
        }
        else{
            on[k] = false;
            if(k == top){
                while(!on[top]) top--;
            }
        }
        py = y;
    }
}

struct Rec{
    int id, area;
    Rec(int id, int area) : id(id), area(area) {}
    bool operator<(const Rec& r) const{
        if(area == r.area) return id > r.id;
        return area < r.area;
    }
};
priority_queue<Rec> pq;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        cin >> xs[i] >> ys[i] >> xe[i] >> ye[i];
        xmax = max(xmax, xe[i]);
        xmin = min(xmin, xs[i]);
        ymax = max(ymax, ye[i]);
        ymin = min(ymin, ys[i]);
    }

    memset(area, 0, sizeof(area));
    for(int x=xmin; x<xmax; x++){
        memset(on, false, sizeof(on));
        on[0] = true;
        sweep(x);
    }

    for(int i=1; i<=N; i++) pq.emplace(i, area[i]);
    vector<int> ans;
    for(int i=0; i<K; i++){
        ans.push_back(pq.top().id);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<K; i++) cout << ans[i] << ' ';
}
