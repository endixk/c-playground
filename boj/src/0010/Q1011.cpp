// Fly me to the Alpha Centauri

#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long x, y;
        cin >> x >> y;

        long long d = y-x;
        long long k = 1;
        while(k*k-k < d) k++;
        k--;

        if(k*k < d) cout << 2*k << endl;
        else cout << 2*k-1 << endl;
    }
}