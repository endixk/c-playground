// BOJ 1042 [DNA]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

string DNA;
string codes[] = {"", "A", "C", "G", "T",
                  "AA", "AC", "AG", "AT",
                  "CA", "CC", "CG", "CT",
                  "GA", "GC", "GG", "GT",
                  "TA", "TC", "TG", "TT"};
map<string, int> aa, codon, cmap;
int dp[2500][21];
int solve(int loc, int code){

}

int main(){
    cin >> DNA;
    int N; cin >> N;

    int aid = 1;
    while(N--){
        string c, a; cin >> c >> a;
        if(aa.find(a) == aa.end()) aa[a] = aid++;
        codon[c] = aa[a];
    }
    for(int i=0; i<21; i++) cmap[codes[i]] = i;

}