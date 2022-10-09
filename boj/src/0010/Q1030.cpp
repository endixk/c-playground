// Fractal plane
// Supported by GitHub Copilot

#include <iostream>
#include <cmath>
using namespace std;

bool isCenter(int x, int y, int k, int sx, int sy, int size){
    int dx = x - sx, dy = y - sy;
    int lb = (size - k) / 2, rb = (size + k) / 2;
    return lb <= dx && dx < rb && lb <= dy && dy < rb;
}

int main(){
    int s, N, K, r1, r2, c1, c2;
    cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;

    if(s == 0){
        cout << 0 << endl;
        return 0;
    }

    for(int x = r1; x <= r2; x++){
        for(int y = c1; y <= c2; y++){
            int tx = x, ty = y, k = int(K * pow(N, s-1)), size = int(pow(N, s));
            bool flag = false;
            for(int step = 0; step < s; step++){
                if(isCenter(tx, ty, k, 0, 0, size)){
                    flag = true;
                    cout << 1;
                    break;
                }

                k /= N;
                size /= N;
                tx %= int(pow(N, s-step-1));
                ty %= int(pow(N, s-step-1));
            }
            if(!flag) cout << 0;
        }
        cout << endl;
    }
}