// Command prompt
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;

    string s, consensus;
    cin >> s;
    consensus = s;

    while(--N){
        cin >> s;
        for(int i = 0; i < s.length(); i++)
            if(consensus[i] != s[i]) consensus[i] = '?';
    }

    cout << consensus << endl;
}