// BOJ 1165 [Word Puzzle]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

char ASCII[] = R"(
 !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~)";
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ifstream fin; ofstream fout;
    fin.open(R"(C:\Users\admin\Desktop\enc.txt)");
    fout.open(R"(C:\Users\admin\CLionProjects\c-playground\boj\extra\Q1165.txt)");
    string s; fin >> s;

    for(int i=0; i<s.size(); i+=61){
        string bin = s.substr(i, 61);
        // cout << bin << ' ';
        long long num = 0;
        for(int j=0; j<61; j++){
            num *= 2;
            num += bin[j] - '0';
        }
        // cout << num << ' ' << char(num) << endl;
        while(num){
            fout << ASCII[num % 118];
            num /= 118;
        }
    }

    // cout << bitset<8>(DB[0]) << endl;
}
