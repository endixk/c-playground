// BOJ 1144 [Cheapest Cost]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define INF 99999999

int N, M, board[9][9];
map<int,int> bit_profile[9][9];

inline int get_bit(int bit, int idx){
    return (bit >> (3 * (M - idx - 1))) & 7;
}
inline int set_bit(int bit, int idx, int val){
    return (bit & ~(7 << (3 * (M - idx - 1)))) | (val << (3 * (M - idx - 1)));
}

int refactor(int p){
    int n;
    int conv[10], idx = 0;
    fill(conv, conv+10, -1);
    conv[0] = 0;
    for(int i=0; i<M; i++){
        if(conv[get_bit(p, i)] < 0) conv[get_bit(p, i)] = ++idx;
        n = set_bit(n, i, conv[get_bit(p, i)]);
    }
    return n;
}

int connect(int p, int y){
    int n = set_bit(p, 0, 0) << 3;
    int head = get_bit(p, 0), tail = get_bit(p, M-1);
    if(y){
        if(head == 0 && tail == 0) n |= 7;
        else if(head == 0) n |= tail;
        else if(tail == 0 || head == tail) n |= head;
        else {
            n |= head;
            for(int i=0; i<M; i++) if(get_bit(n, i) == tail) n = set_bit(n, i, head);
        }
    }
    else{
        if(head == 0) n |= 7;
        else n |= head;
    }
    return refactor(n);
}

int count(int p){
    int cnt = 0;
    bool hit[10]; memset(hit, false, sizeof(hit));
    for(int i=0; i<M; i++){
        if(!hit[get_bit(p, i)]){
            hit[get_bit(p, i)] = true, cnt++;
        }
    }
    return cnt - hit[0];
}

bool safe(int p){
    if(get_bit(p, 0) == 0) return true;
    for(int i=1; i<M; i++) if(get_bit(p, i) == get_bit(p, 0)) return true;
    return false;
}

int dp(int x, int y, int p){
    p = refactor(p);
    if(x == N) return count(p) <= 1 ? 0 : INF;
    if(bit_profile[x][y].find(p) != bit_profile[x][y].end()) return bit_profile[x][y][p];

    int ret = INF, nx = x, ny = y+1;
    if(ny == M) nx++, ny = 0;

    if(safe(p)) ret = min(ret, dp(nx, ny, set_bit(p, 0, 0) << 3));
    ret = min(ret, dp(nx, ny, connect(p, y)) + board[x][y]);
    if(count(p) <= 1) ret = min(ret, 0);

    return bit_profile[x][y][p] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> board[i][j];
    cout << dp(0, 0, 0);
}

