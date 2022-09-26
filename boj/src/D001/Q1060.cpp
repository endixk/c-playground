// BOJ 1060 [Good Number]
// Supported by GitHub Copilot

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L; cin >> L;
    int arr[L+1]; arr[0] = 0;
    for (int i = 1; i <= L; i++) cin >> arr[i];
    sort(arr, arr + L + 1);
    int n; cin >> n;

    // numbers with priority zero
    for(int i = 1; i <= L; i++){
        if(arr[i-1] + 1 == arr[i] - 1){
            cout << arr[i-1] + 1 << ' ';
            if(--n == 0){
                cout << '\n';
                return 0;
            }
        }
        cout << arr[i] << ' ';
        if(--n == 0){
            cout << '\n';
            return 0;
        }
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    int fptr[L], bptr[L];
    for(int i = 0; i < L; i++){
        fptr[i] = arr[i] + 1;
        bptr[i] = arr[i+1] - 1;
        if(fptr[i] < bptr[i]){
            pq.emplace((long long) (arr[i+1] - fptr[i]) * (fptr[i] - arr[i]), fptr[i]);
            fptr[i]++;
            pq.emplace((long long) (arr[i+1] - bptr[i]) * (bptr[i] - arr[i]), bptr[i]);
            bptr[i]--;
        }
    }

    while(!pq.empty()){
        auto [_, num] = pq.top(); pq.pop();
        cout << num << ' ';
        if(--n == 0){
            cout << '\n';
            return 0;
        }
        for(int i = 0; i < L; i++){
            if(fptr[i] == num+1){
                if(fptr[i] <= bptr[i]){
                    pq.emplace((long long) (arr[i+1] - fptr[i]) * (fptr[i] - arr[i]), fptr[i]);
                    fptr[i]++;
                }
                break;
            }
            if(bptr[i] == num-1){
                if(fptr[i] <= bptr[i]){
                    pq.emplace((long long) (arr[i+1] - bptr[i]) * (bptr[i] - arr[i]), bptr[i]);
                    bptr[i]--;
                }
                break;
            }
        }
    }

    int x = arr[L] + 1;
    while(n--){
        cout << x << ' ';
        x++;
    }
    cout << '\n';
}
