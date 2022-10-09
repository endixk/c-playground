// BOJ 1043 [Lies]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int parent[51];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) parent[i] = i;

    int T; cin >> T;
    if(T == 0) {
        cout << M << '\n';
        return 0;
    }

    bool know[51] = {false, };
    for (int i=0; i<T; i++) {
        int x; cin >> x;
        know[x] = true;
    }

    int party[51][51] = {0, };
    for (int i=0; i<M; i++) {
        int P; cin >> P;
        int host; cin >> host;
        party[i][0] = host;
        for(int j=1; j<P; j++) {
            int guest; cin >> guest;
            party[i][j] = guest;
            uni(host, guest);
        }
        party[i][P] = -1;
    }

    // union-find
    int val = 0;
    for (int i=0; i<M; i++){
        bool flag = false;
        for(int j=0; j<51; j++){
            if(party[i][j] == -1) break;
            for(int k=1; k<=N; k++){
                if(!know[k]) continue;
                if(find(party[i][j]) == find(k)) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) val++;
    }

    cout << val << '\n';
}