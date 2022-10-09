// Series sum
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    int go = -1;
    for(int l = L; l <= 100; l++){
        if(2*N >= l*l - l){
            if(l%2 == 0){
                if((2*N + l) % (2*l) == 0)
                    go = (2*N + l - l*l) / (2*l);
            }
            else if(N % l == 0)
                go = (2*N + l - l*l) / (2*l);
        }
        if(go >= 0){
            for(int i = 0; i < l; i++)
                cout << go + i << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}