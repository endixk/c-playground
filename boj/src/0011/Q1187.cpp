// BOJ 1187 [Playing with Numbers]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define NV pair<int,vector<int>>

NV merge(const NV& a, const NV& b){
    vector<int> v;
    v.reserve(a.second.size() + b.second.size());
    merge(a.second.begin(), a.second.end(), b.second.begin(), b.second.end(), back_inserter(v));
    return {a.first + b.first, v};
}
pair<NV,NV> split(const NV& v, int n){
    int s = 0;
    for(int i=0; i<n; i++) s += v.second[i];
    return {
        {s, vector<int>(v.second.begin(), v.second.begin()+n)},
        {v.first-s, vector<int>(v.second.begin()+n, v.second.end())}
    };
}

pair<NV,NV> solve(const NV& v, int k){
    if(k == 0) return {v,{0, {}}};
    NV nv1, nv2, nv3;
    NV sol, ori, rej;
    tie(sol, ori) = split(v, (1<<k)-1);
    tie(nv1, rej) = solve(sol, k-1);
    ori = merge(ori, rej);
    tie(sol, ori) = split(ori, (1<<k)-1);
    tie(nv2, rej) = solve(sol, k-1);
    ori = merge(ori, rej);
    tie(sol, ori) = split(ori, (1<<k)-1);
    tie(nv3, rej) = solve(sol, k-1);
    ori = merge(ori, rej);

    if(nv1.first % (1<<k) == nv2.first % (1<<k)) return {merge(nv1, nv2), merge(nv3, ori)};
    if(nv1.first % (1<<k) == nv3.first % (1<<k)) return {merge(nv1, nv3), merge(nv2, ori)};
    return {merge(nv2, nv3), merge(nv1, ori)};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, k; cin >> N;
    for(k=0; (1<<k) < N; k++);

    vector<int> v(2*N-1); int s = 0;
    for(int i=1; i<2*N; i++) cin >> v[i-1], s += v[i-1];
    for(int c : solve({s, v}, k).first.second) cout << c << ' ';
}
