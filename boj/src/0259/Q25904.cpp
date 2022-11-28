#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, i=1; cin >> N >> X;
    int T[N]; for(int& t : T) cin >> t;
    while(true){
        if(T[i-1] < X++) break;
        if(++i > N) i = 1;
    }
    cout << i;
}