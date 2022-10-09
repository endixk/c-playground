// BOJ 1062 [Education]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

int wmask[50];
bool visited[26];
int N, K;
int mask = 0, MAX = 0;

void DFS(char c, int depth){
    if(depth == K){
        int cnt = 0;
        for(int i=0; i<N; i++){
            if((wmask[i] & mask) == wmask[i]) cnt++;
        }
        if(MAX < cnt) MAX = cnt;
        return;
    }
    for(int i=c-'a'; i<26; i++){
        if(!visited[i]){
            visited[i] = true;
            mask |= (1 << i);
            DFS('a' + i, depth+1);
            visited[i] = false;
            mask &= ~(1 << i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    string words[N];
    for (int i = 0; i < N; i++) cin >> words[i];

    // bitmask of words
    for (int i = 0; i < N; i++) {
        wmask[i] = 0;
        for (int j = 0; j < words[i].length(); j++) {
            wmask[i] |= (1 << (words[i][j] - 'a'));
        }
    }

    // exceptions
    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }
    if (K == 26) {
        cout << N << '\n';
        return 0;
    }

    // mask 'a', 'n', 't', 'i', 'c'
    for(char c : "antic") {
        visited[c - 'a'] = true;
        mask |= (1 << (c - 'a'));
    }

    // DFS
    DFS('a', 5);
    cout << MAX << '\n';
}
