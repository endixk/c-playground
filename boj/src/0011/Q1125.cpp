// BOJ 1125 [Floor Decoration]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll size[6]; fill(size, size+6, 0);
    ll xl = (x1 + 4) / 5 * 5, xr = x2 - x2 % 5, yu = (y1 + 4) / 5 * 5, yd = y2 - y2 % 5;
    ll xn = (xr > xl ? xr - xl : 0) / 5, yn = (yd > yu ? yd - yu : 0) / 5;
    // interior
    size[5] += xn * yn * 5;
    // top and bottom
    if(xn > 0){
        // 1: horizontal, 0: vertical
        bool top = ((xl / 5) % 2) ^ ((yu / 5) % 2);
        bool bot = ((xl / 5) % 2) ^ ((yd / 5 + 1) % 2);
        ll th, tv, bh, bv;
        if(xn % 2){
            if(top) th = xn/2 + 1, tv = xn/2;
            else th = xn/2, tv = xn/2 + 1;
            if(bot) bh = xn/2 + 1, bv = xn/2;
            else bh = xn/2, bv = xn/2 + 1;
        }
        else th = tv = bh = bv = xn/2;

        if(yd < yu){
            size[5] += th * (y2 - y1);
            size[y2 - y1] += tv * 5;
        }
        else{
            // top
            size[5] += th * (yu - y1);
            size[yu - y1] += tv * 5;
            // bottom
            size[5] += bh * (y2 - yd);
            size[y2 - yd] += bv * 5;
        }
    }
    // left and right
    if(yn > 0){
        // 1: horizontal, 0: vertical
        bool left = ((xl / 5 - 1) % 2) ^ ((yu / 5 + 1) % 2);
        bool right = ((xr / 5) % 2) ^ ((yu / 5 + 1) % 2);
        ll lh, lv, rh, rv;
        if(yn % 2){
            if(left) lh = yn/2 + 1, lv = yn/2;
            else lh = yn/2, lv = yn/2 + 1;
            if(right) rh = yn/2 + 1, rv = yn/2;
            else rh = yn/2, rv = yn/2 + 1;
        }
        else lh = lv = rh = rv = yn/2;

        if(xr < xl){
            size[x2 - x1] += lh * 5;
            size[5] += lv * (x2 - x1);
        }
        else{
            // left
            size[5] += lv * (xl - x1);
            size[xl - x1] += lh * 5;
            // right
            size[5] += rv * (x2 - xr);
            size[x2 - xr] += rh * 5;
        }
    }
    // corners
    if(xl > xr && yu > yd){
        bool hor = ((xr / 5) % 2) ^ ((yd / 5 + 1) % 2);
        if(hor) size[x2 - x1] += y2 - y1;
        else size[y2 - y1] += x2 - x1;
    }
    else if(xl > xr){
        bool top = ((xr / 5) % 2) ^ ((yu / 5) % 2);
        if(top) size[x2 - x1] += yu - y1;
        else size[yu - y1] += x2 - x1;
        bool bot = ((xr / 5) % 2) ^ ((yd / 5 + 1) % 2);
        if(bot) size[x2 - x1] += y2 - yd;
        else size[y2 - yd] += x2 - x1;
    }
    else if(yu > yd){
        bool left = ((xl / 5 - 1) % 2) ^ ((yu / 5) % 2);
        if(left) size[xl - x1] += y2 - y1;
        else size[y2 - y1] += xl - x1;
        bool right = ((xr / 5) % 2) ^ ((yu / 5) % 2);
        if(right) size[x2 - xr] += y2 - y1;
        else size[y2 - y1] += x2 - xr;
    }
    else{
        bool tl = ((xl / 5 - 1) % 2) ^ ((yu / 5) % 2);
        if(tl) size[xl - x1] += yu - y1;
        else size[yu - y1] += xl - x1;
        bool tr = ((xr / 5) % 2) ^ ((yu / 5) % 2);
        if(tr) size[x2 - xr] += yu - y1;
        else size[yu - y1] += x2 - xr;
        bool bl = ((xl / 5 - 1) % 2) ^ ((yd / 5 + 1) % 2);
        if(bl) size[xl - x1] += y2 - yd;
        else size[y2 - yd] += xl - x1;
        bool br = ((xr / 5) % 2) ^ ((yd / 5 + 1) % 2);
        if(br) size[x2 - xr] += y2 - yd;
        else size[y2 - yd] += x2 - xr;
    }

    // debug
    // for(int i = 1; i < 6; i++) cout << size[i] << ' ';
    // cout << endl;

    ll cnt = 0;
    cnt += size[5];
    cnt += size[4]; size[1] -= size[4];
    cnt += size[3]; size[2] -= size[3];
    if(size[2] > 0){
        cnt += size[2] / 2; size[1] -= size[2] / 2;
        cnt += size[2] % 2; size[1] -= 3*(size[2] % 2);
    }
    else size[1] += 2*size[2];
    if(size[1] > 0) cnt += size[1] / 5 + (size[1] % 5 > 0);
    cout << cnt;
}
