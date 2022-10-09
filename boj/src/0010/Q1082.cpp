// BOJ 1082 [Room Number]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(vector<int> x, vector<int> y) {
    bool flag = false;
    for(int v : x) if(v > 0) flag = true;
    if(!flag) return false;
    if(x.size() != y.size()) return x.size() > y.size();
    for(int i=0; i<x.size(); i++) {
        if(x[i] != y[i]) return x[i] > y[i];
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int P[N];
    for (int i = 0; i < N; i++) cin >> P[i];
    int M; cin >> M;

    vector<int> trace[M+1];
    for(int m=1; m<=M; m++){
        trace[m] = vector<int>();
        for(int i=N-1; i>=0; i--){
            if(m-P[i] >= 0){
                vector<int> tmp;
                for(int t : trace[m-P[i]]) tmp.push_back(t);
                int loc; for(loc=0; loc<tmp.size() && tmp[loc] > i; loc++);
                tmp.insert(tmp.begin()+loc, i);
                if(compare(tmp, trace[m])) trace[m] = tmp;
            }
        }
    }

    // find max and trace
    vector<int> MAX = trace[M];
    for(int i=M-1; i>0; i--)
        if(compare(trace[i], MAX))
            MAX = trace[i];

    if(MAX.empty()) cout << 0;
    else for(int v : MAX) cout << v;
}
