// BOJ 1129 [Heights]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

int sim_remove(vector<int> vec, int x){
    vec.erase(find(vec.begin(), vec.end(), x));
    int ret = 0;
    for(int i=1; i<vec.size(); ++i) ret = max(ret, vec[i]-vec[i-1]);
    return ret;
}

int sim_insert(vector<int> vec, int x){
    vec.insert(lower_bound(vec.begin(), vec.end(), x), x);
    int ret = 0;
    for(int i=1; i<vec.size(); ++i) ret = max(ret, vec[i]-vec[i-1]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end());

    vector<int> lvec = vec, rvec = {vec[0], vec[N-1]};
    vector<int> lcpy = lvec, rcpy = rvec;

    int lmax, rmax;
    while(true){
        lmax = rmax = 0;
        for(int i=1; i<lvec.size(); ++i) lmax = max(lmax, lvec[i]-lvec[i-1]);
        for(int i=1; i<rvec.size(); ++i) rmax = max(rmax, rvec[i]-rvec[i-1]);
        int prev = max(lmax, rmax), next = prev, loc = -1;
        for(int i=1; i<lvec.size()-1; ++i){
            int lnext = sim_remove(lvec, lvec[i]);
            int rnext = sim_insert(rvec, lvec[i]);
            if(next >= max(lnext, rnext)){
                loc = i;
                next = max(lnext, rnext);
            }
        }
        if(loc < 0) break;
        int val = lvec[loc];
        lvec.erase(find(lvec.begin(), lvec.end(), val));
        rvec.insert(lower_bound(rvec.begin(), rvec.end(), val), val);
        if(prev > next) lcpy = lvec, rcpy = rvec;
    }

    cout << vec[0] << ' ';
    for(size_t i=1; i<lcpy.size()-1; ++i) cout << lcpy[i] << ' ';
    cout << vec[N-1] << ' ';
    for(size_t i=rcpy.size()-1; i>1; --i) cout << rcpy[i-1] << ' ';
}
