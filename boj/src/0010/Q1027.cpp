// Skyscrapers
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

bool visible(const int *arr, int x, int y){
    if(x == y) return false;
    if(x > y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    int hx = arr[x], hy = arr[y];

    for(int i = x+1; i < y; i++){
        int h = arr[i];
        if(h >= (double) (hy - hx) / (y - x) * (i - x) + hx) return false;
    }

    return true;
}

int main(){
    int N;
    cin >> N;

    int arr[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];

    int MAX = 0;
    for(int i=0; i<N; i++){
        int cnt = 0;
        for(int j=0; j<N; j++){
            if(visible(arr, i, j)) cnt++;
        }
        if(MAX < cnt) MAX = cnt;
    }
    cout << MAX << endl;
}