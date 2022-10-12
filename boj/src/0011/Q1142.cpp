// BOJ 1142 [Pizza]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct vec{
    ll x, y;
    vec(ll x, ll y): x(x), y(y) {}
    vec operator+(const vec &rhs) const {
        return {x+rhs.x, y+rhs.y};
    }
    vec operator-(const vec &rhs) const {
        return {x-rhs.x, y-rhs.y};
    }
    ll operator*(const vec &rhs) const {
        return x*rhs.x + y*rhs.y;
    }
    bool operator==(const vec &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

bool perp(const vec &a, const vec &b) {
    return a*b == 0;
}
bool para(const vec &a, const vec &b) {
    return (a*b)*(a*b) == (a*a)*(b*b);
}

vector<vec> vx;
bool beautiful(vec v){
    vector<vec> tmp;

    // include points on the line
    for(vec w: vx) if(para(v, w)) tmp.push_back(w);

    // include pairs
    bool flag;
    for(int i=0; i<vx.size(); i++){
        if(para(v, vx[i])) continue;
        for(int j=i+1; j<vx.size(); j++){
            if(para(v, vx[j])) continue;
            flag = false;
            for(vec t : tmp) if(t == vx[i] || t == vx[j]) {
                flag = true;
                break;
            }
            if(flag) continue;
            vec s = vx[i] + vx[j], t = vx[i] - vx[j];
            if(s == vec(0, 0)) s = vec(-vx[i].y, vx[i].x);
            if(para(v, s) && perp(v, t)){
                tmp.push_back(vx[i]);
                tmp.push_back(vx[j]);
            }
        }
    }

    return vx.size() == tmp.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int x, y; cin >> x >> y;
        if(x == 0 && y == 0){
            if(N == 1){
                cout << -1;
                return 0;
            }
            continue;
        }
        vx.emplace_back(x, y);
    }

    vector<vec> ans;
    // point vectors
    for (vec v : vx) {
        bool flag = true;
        for(vec a : ans) if(para(v, a)) {
            flag = false;
            break;
        }
        if(flag && beautiful(v))
            ans.push_back(v);
    }
    // vector pairs
    for (int i=0; i<vx.size(); i++){
        for (int j=i+1; j<vx.size(); j++){
            vec s = vx[i]+vx[j];
            if(s == vec(0, 0)) s = vec(-vx[i].y, vx[i].x);
            bool flag = true;
            for (vec a : ans) if(para(s, a)) {
                flag = false;
                break;
            }
            if(flag && beautiful(s))
                ans.push_back(s);
        }
    }

    cout << ans.size();
}
