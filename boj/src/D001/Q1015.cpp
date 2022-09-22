// Sequence sort

#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int arr[N], ord[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    while(cnt < N){
        // find min
        int val = 10000;
        for(int i = 0; i < N; i++)
            if(val > arr[i])
                val = arr[i];

        // assign order
        for(int i = 0; i < N; i++)
            if(arr[i] == val) {
                ord[i] = cnt++;
                arr[i] = 10000;
            }
    }

    // print order
    for(int i = 0; i < N; i++)
        cout << ord[i] << " ";
    cout << endl;
}