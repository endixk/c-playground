// BOJ 2608 [Roman Numerals]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

map<char,int> C = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
};
vector<int> K = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9 ,5, 4, 1};
vector<string> V = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX" ,"V", "IV", "I"};
int rtoi(string r) {
    int ret = 0;
    for (int i=0; i<r.length(); i++) {
        ret += C[r[i]] * (i+1 < r.length() && C[r[i]] < C[r[i+1]] ? -1 : 1);
    }
    return ret;
}
string itor(int x) {
    string ret;
    while (x > 0) {
        for (int i=0; i<K.size(); i++) {
            if (x >= K[i]) { x -= K[i]; ret += V[i]; break;}
        }
    }
    return ret;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int x = rtoi(s) + rtoi(t);
    cout << x << '\n' << itor(x) << '\n';
}
