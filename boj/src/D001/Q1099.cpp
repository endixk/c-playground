// BOJ 1099 [Unknown Sentence]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool conv(string frag, string word){
    char f[frag.size()], w[word.size()];
    for(int i=0; i<frag.size(); i++) f[i] = frag[i];
    for(int i=0; i<word.size(); i++) w[i] = word[i];
    sort(f, f+frag.size());
    sort(w, w+word.size());
    for(int i=0; i<frag.size(); i++) if(f[i] != w[i]) return false;
    return true;
}

int price(string frag, string word){
    int ret = 0;
    for(int i=0; i<frag.size(); i++){
        if(frag[i] != word[i]) ret++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sent; cin >> sent;
    int N, L = sent.size(); cin >> N;
    string words[N];
    for (int i = 0; i < N; i++) cin >> words[i];

    int DP[L+1];
    for(int i=0; i<=L; i++) DP[i] = 1e9;
    DP[0] = 0;
    for(int i = 1; i <= L; i++){
        for(int j = 0; j < i; j++){
            for(const string& word : words){
                if(word.size() != i-j) continue;
                if(!conv(sent.substr(j, i-j), word)) continue;
                DP[i] = min(DP[i], DP[j] + price(sent.substr(j, i-j), word));
            }
        }
    }

    if(DP[L] == 1e9) cout << -1;
    else cout << DP[L];
}
