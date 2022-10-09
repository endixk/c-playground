// Le Petit Prince

#include <iostream>
using namespace std;

bool enclose(int px, int py, int cx, int cy, int cr){
    return (px-cx)*(px-cx) + (py-cy)*(py-cy) < cr*cr;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;
        int cnt = 0;
        while(n--){
            int x, y, r;
            cin >> x >> y >> r;
            if(enclose(x1, y1, x, y, r) != enclose(x2, y2, x, y, r))
                cnt++;
        }

        cout << cnt << endl;
    }
}