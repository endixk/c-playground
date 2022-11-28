#include <bits/stdc++.h>
using namespace std;

int main(){
    double prob[10];
    for(double & p : prob) cin >> p;

    int perm[10] = {0,1,2,3,4,5,6,7,8,9};
    double ans = 0;
    do{
        double p = 1;
        for(int i=1; i<10; i++) p *= prob[perm[i]] / i * 10;
        ans = max(ans, p);
    } while(next_permutation(perm, perm+10));
    cout << fixed << setprecision(10) << ans;
}