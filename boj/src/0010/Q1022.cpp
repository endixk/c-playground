// Pretty spiral
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int spiral(int x, int y){
    int d = max(abs(x), abs(y));
    int base = (d*2 + 1) * (d*2 + 1);
    if(x == d) return base - d + y;
    if(y == -d) return base - 3*d + x;
    if(x == -d) return base - 5*d - y;
    return base - 7*d - x;
}

int ndigit(int n){
    int d = 0;
    while(n){
        n /= 10;
        d++;
    }
    return d;
}

int main(){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int MAX = 0;
    for(int i = r1; i <= r2; i++)
        for(int j = c1; j <= c2; j++)
            MAX = max(MAX, spiral(i, j));

    int buf = ndigit(MAX);
    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            int d = ndigit(spiral(i, j));
            for(int k = 0; k < buf - d; k++)
                cout << ' ';
            cout << spiral(i, j) << ' ';
        }
        cout << endl;
    }
}