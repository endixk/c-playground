// BOJ 1078 [Reversal]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> find(ll D, int n){
    vector<int> v;
    for(int i=0; i<n/2; i++){
        ll factor = 1;
        for(int j=0; j<n-2*i-1; j++) factor *= 10;
        factor--;

        ll rem = 10 - (D>0 ? D:-D) % 10;
        if(rem == 10) rem = 0;
        if(D < 0) rem = -rem;

        v.push_back((int) rem);
        D -= (ll) rem * factor;
        D /= 10;
    }
    if(D != 0) v.clear();
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D; cin >> D;
    int n=0; for(int i=1; i<=D; i*=10) n++;

    // brute force through magnitudes
    for(; n<19; n++){
         vector<int> v = find(D, n);
         if(!v.empty()){
             vector<int> res;
             if(n%2 == 1) res.push_back(0);
             for(int i=v.size()-1; i>=0; i--){
                 if(v[i] > 0){
                     res.insert(res.begin(), v[i]);
                     res.push_back(0);
                 }
                 else{
                     res.insert(res.begin(), 0);
                     res.push_back(-v[i]);
                 }
             }
             if(res[0] == 0) res[0] = res[res.size() - 1] = 1;
             for(int i : res) cout << i;
             return 0;
         }
    }
    cout << -1;
}
