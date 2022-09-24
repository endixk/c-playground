// BOJ 1047 [Fence]
// Supported by GitHub Copilot

#include <iostream>
#include <algorithm>
using namespace std;

bool inside(int x, int y, int p1, int p2, int q1, int q2){
    return (p1 <= x && x <= q1 && p2 <= y && y <= q2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int x[N], y[N], f[N];
    for(int i=0; i<N; i++) cin >> x[i] >> y[i] >> f[i];

    // sort tree indices by their value with insertion sort
    int tf[N], idx[N], loc=0;
    for(int i=0; i<N; i++) tf[i] = f[i];
    for(int i=0; i<N; i++){
        int m = 0, mi = 0;
        for(int j=0; j<N; j++){
            if(m < tf[j]){
                m = tf[j];
                mi = j;
            }
        }
        idx[loc++] = mi;
        tf[mi] = 0;
    }

    // sort x and y coordinates
    int sx[N], sy[N];
    for(int i=0; i<N; i++){
        sx[i] = x[i];
        sy[i] = y[i];
    }
    sort(sx, sx+N);
    sort(sy, sy+N);

    // for every possible fence structures
    int MIN = N;
    for(int p1=0; p1<N; p1++){
        for(int p2=p1; p2<N; p2++){
            for(int q1=0; q1<N; q1++){
                for(int q2=q1; q2<N; q2++){
                    int fence = (sx[p2] - sx[p1]) * 2 + (sy[q2] - sy[q1]) * 2;
                    int count = 0;

                    // check trees inside the fence
                    bool in[N];
                    for(int i=0; i<N; i++) in[i] = inside(x[i], y[i], sx[p1], sy[q1], sx[p2], sy[q2]);

                    // cut down all trees outside the fence
                    for(int i=0; i<N; i++){
                        if(!in[idx[i]]){
                            fence -= f[idx[i]];
                            count++;
                        }
                    }

                    if(fence <= 0){
                        MIN = min(MIN, count);
                        continue;
                    }

                    // cut down trees inside the fence greedily
                    for(int i=0; i<N; i++){
                        if(in[idx[i]]){
                            fence -= f[idx[i]];
                            count++;
                            if(fence <= 0){
                                MIN = min(MIN, count);
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << MIN << '\n';
}