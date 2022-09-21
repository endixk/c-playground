// Distributed processing

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> r2 = {2, 4, 8, 6};
    vector<int> r3 = {3, 9, 7, 1};
    vector<int> r4 = {4, 6};
    vector<int> r7 = {7, 9, 3, 1};
    vector<int> r8 = {8, 4, 2, 6};
    vector<int> r9 = {9, 1};

    while(T--){
        int a, b;
        cin >> a >> b;
        switch(a%10){
            case 0:
                cout << 10 << endl;
                break;
            case 1:
                cout << 1 << endl;
                break;
            case 2:
                cout << r2[--b%4] << endl;
                break;
            case 3:
                cout << r3[--b%4] << endl;
                break;
            case 4:
                cout << r4[--b%2] << endl;
                break;
            case 5:
                cout << 5 << endl;
                break;
            case 6:
                cout << 6 << endl;
                break;
            case 7:
                cout << r7[--b%4] << endl;
                break;
            case 8:
                cout << r8[--b%4] << endl;
                break;
            case 9:
                cout << r9[--b%2] << endl;
                break;
        }
    }
}