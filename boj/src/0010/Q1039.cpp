// BOJ 1039 [Exchange]
// Supported by GitHub Copilot

#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main(){
    string N; int K; cin >> N >> K;
    int n = N.size();
    queue<string> q;
    q.push(N);

    while(K--){
        set<string> visited;
        int qsize = q.size();
        // for each queue element
        for(int i = 0; i < qsize; i++){
            string s = q.front(); q.pop();
            // swap every pair
            for(int j = 0; j < n; j++){
                for(int k = j+1; k < n; k++){
                    // reject zero leadings
                    if(j == 0 && s[k] == '0') continue;
                    swap(s[j], s[k]);
                    if(visited.find(s) == visited.end()){
                        q.push(s);
                        visited.insert(s);
                    }
                    swap(s[j], s[k]);
                }
            }
        }
    }

    int MAX = -1;
    while(!q.empty()){
        MAX = max(MAX, stoi(q.front()));
        q.pop();
    }
    cout << MAX << endl;
}