// Lamps
// Supported by GitHub Copilot

#include <iostream>
#include <string>
#include <map>
using namespace std;

int zeros(string s){
    int cnt = 0;
    for(char c : s)
        if(c == '0') cnt++;
    return cnt;
}

int main(){
    int N, M;
    cin >> N >> M;

    string lamps[N];
    map<string, int> cmap;
    for(int i = 0; i < N; i++)
        cin >> lamps[i];
    for(string lamp : lamps){
        if(cmap.find(lamp) == cmap.end())
            cmap[lamp] = 1;
        else
            cmap[lamp]++;
    }

    int K, MAX = 0;
    cin >> K;
    for(auto & p : cmap){
        int zero = zeros(p.first);
        if(zero <= K && (K - zero) % 2 == 0)
            MAX = max(MAX, p.second);
    }

    cout << MAX << endl;
}