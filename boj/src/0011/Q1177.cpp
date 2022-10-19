// BOJ 1177 [Cattle Bruisers]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define MAX 50001
typedef pair<double,double> pdd;

int N, R;
int x[MAX], y[MAX], vx[MAX], vy[MAX];

vector<pdd> inters;
struct comp {
    bool operator()(const pdd &a, const pdd &b) {
        return a.second > b.second;
    }
};
priority_queue<pdd, vector<pdd>, comp> pq;
int overlap(){
    sort(inters.begin(), inters.end());
    int ret = 0, cnt = 0;
    for (auto & inter : inters) {
        while (!pq.empty() && pq.top().second < inter.first) {
            pq.pop();
            cnt--;
        }
        pq.push(inter);
        cnt++;
        ret = max(ret, cnt);
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // input
    int bx, by, bvx, bvy;
    cin >> N >> R >> bx >> by >> bvx >> bvy;
    for(int i=0; i<N; i++){
        int cx, cy, cvx, cvy;
        cin >> cx >> cy >> cvx >> cvy;
        x[i] = cx - bx;
        y[i] = cy - by;
        vx[i] = cvx - bvx;
        vy[i] = cvy - bvy;
    }

    // find intervals
    int stop = 0; // stopped bruiser within range
    for(int i=0; i<N; i++){
        if(vx[i] == 0 && vy[i] == 0){
            stop += (x[i]*x[i] + y[i]*y[i] <= R*R);
            continue;
        }
        double c = -(x[i]*vx[i] + y[i]*vy[i]) / sqrt(vx[i]*vx[i] + vy[i]*vy[i]);
        if(R*R >= x[i]*x[i] + y[i]*y[i] - c*c){
            double d = sqrt(R*R - x[i]*x[i] - y[i]*y[i] + c*c);
            double t1 = (c - d) / sqrt(vx[i]*vx[i] + vy[i]*vy[i]);
            double t2 = (c + d) / sqrt(vx[i]*vx[i] + vy[i]*vy[i]);
            if(t2 < 0) continue;
            if(t1 < 0) t1 = 0;
            inters.emplace_back(t1, t2);
        }
    }

    cout << overlap() + stop;
}
