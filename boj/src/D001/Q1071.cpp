// BOJ 1071 [Sort]
// Supported by GitHub Copilot

#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        m[x]++;
    }

    for(int i = 0; i <= 1000; i++){
        if(m[i] > 0){
            if(m[i+1] == 0){
                for(int j = 0; j < m[i]; j++) cout << i << ' ';
                m[i] = 0;
                continue;
            }

            bool flag = false;
            for(int n = i+2; n <= 1000; n++){
                if(m[n] > 0) {
                    for (int j = 0; j < m[i]; j++) cout << i << ' ';
                    cout << n << ' ';
                    m[i] = 0;
                    m[n]--;
                    flag = true;
                    break;
                }
            }

            if(!flag){
                for(int j = 0; j < m[i+1]; j++) cout << i+1 << ' ';
                for(int j = 0; j < m[i]; j++) cout << i << ' ';
                m[i] = 0;
                m[i+1] = 0;
            }
        }
    }
}
