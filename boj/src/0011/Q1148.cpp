// BOJ 1148 [Word Puzzle]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

vector<string> dict, boards;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string buf; cin >> buf;
    while (buf != "-"){
        dict.push_back(buf);
        cin >> buf;
    }
    cin >> buf;
    while (buf != "#"){
        boards.push_back(buf);
        cin >> buf;
    }

    for(const string& board : boards){
        map<char,int> cnt, score;
        for(char c : board) cnt[c]++, score[c] = 0;
        for(const string& word : dict){
            map<char,int> wcnt;
            for(char c : word) wcnt[c]++;
            bool flag = true;
            for(const auto& [c, n] : wcnt){
                if (cnt[c] < n) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for(const auto& [c, n] : wcnt) score[c]++;
            }
        }

        int maxs = 0, mins = 1e9;
        for(const auto& [c, n] : score){
            maxs = max(maxs, n);
            mins = min(mins, n);
        }
        for(const auto& [c, n] : score){
            if (n == mins) cout << c;
        }
        cout << ' ' << mins << ' ';
        for(const auto& [c, n] : score){
            if (n == maxs) cout << c;
        }
        cout << ' ' << maxs << '\n';
    }
}
