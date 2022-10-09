// Contact

#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;

        bool valid = true;
        int i = 0;
        while(true){
            if(s[i] == '0'){
                i++;
                if(i == s.size() || s[i] != '1'){
                    valid = false;
                    break;
                }
                i++;
                if(i == s.size()) break;
            }
            else{ // if(s[i] == '1')
                i++;
                if(i == s.size() || s[i] != '0'){
                    valid = false;
                    break;
                }
                i++;
                if(i == s.size() || s[i] != '0'){
                    valid = false;
                    break;
                }
                while(i < s.size() && s[i] == '0'){
                    i++;
                }
                if(i == s.size()){
                    valid = false;
                    break;
                }
                int cnt = 0;
                while(i < s.size() && s[i] == '1'){
                    i++;
                    cnt++;
                }
                if(i == s.size()){
                    break;
                }
                if(s[i+1] == '0' && cnt > 1) i--;
            }
        }

        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}