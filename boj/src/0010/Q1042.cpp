// BOJ 1042 [Codon]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    string DNA; cin >> DNA;
    int N; cin >> N;

    map<string, int> aa;
    map<string, int> codon;
    int aid = 1;
    while(N--){
        string c, a; cin >> c >> a;
        if(aa.find(a) == aa.end()) aa[a] = aid++;
        codon[c] = aa[a];
    }

    string codes[] = {"", "A", "C", "G", "T",
                      "AA", "AC", "AG", "AT",
                      "CA", "CC", "CG", "CT",
                      "GA", "GC", "GG", "GT",
                      "TA", "TC", "TG", "TT"};
    map<string, int> cmap;
    for(int i=0; i<21; i++) cmap[codes[i]] = i;

    int edp[DNA.length()][21]; // number of end-points
    for(int i=0; i<DNA.length(); i++)
        for(int j=0; j<21; j++)
            edp[i][j] = 0;

    edp[0][0] = edp[0][cmap[DNA.substr(0, 1)]] = 1;
    for(int i=1; i<DNA.length(); i++){
        edp[i][0] = 1;
        for(int x=0; x<i; x++) {
            for(int j=0; j<5; j++) {
                string next = codes[j] + DNA.substr(i, 1);
                edp[i][cmap[next]] += edp[x][j];
            }
        }
    }

    return 0;
}