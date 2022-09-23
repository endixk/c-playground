// 36-based numbers
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

char ord(char c){
    if(c >= '0' && c <= '9') return (char)(c);
    return char(c + 7);
}
int chr(char c){
    if(c >= '0' && c <= '9') return (int)(c - '0');
    return (int)(c - 'A' + 10);
}
string sum(string a, string b){
    int la = a.length(), lb = b.length();
    if(la < lb) for(int i = 0; i < lb - la; i++) a = '0' + a;
    else for(int i = 0; i < la - lb; i++) b = '0' + b;
    if(la > lb) lb = la;
    else la = lb;

    string res;
    int carry = 0;

    for(int i = la - 1; i >= 0; i--){
        int sum = chr(a[i]) + chr(b[i]) + carry;
        res = ord((char)(sum % 36 + '0')) + res;
        carry = sum / 36;
    }
    if(carry) res = ord((char)(carry + '0')) + res;
    return res;
}

string sub(string a, string b){
    int la = a.length(), lb = b.length();
    if(la < lb) for(int i = 0; i < lb - la; i++) a = '0' + a;
    else for(int i = 0; i < la - lb; i++) b = '0' + b;

    string res;
    int carry = 0;

    for(int i = la - 1; i >= 0; i--){
        int sub = chr(a[i]) - chr(b[i]) - carry;
        carry = 0;
        if(sub < 0){
            sub += 36;
            carry = 1;
        }
        res = ord((char)(sub + '0')) + res;
    }
    while(res.length() > 1 && res[0] == '0') res = res.substr(1);
    return res;
}

int compare(string a, string b){
    int la = a.length(), lb = b.length();
    if(la < lb) return -1;
    else if(la > lb) return 1;
    else{
        for(int i = 0; i < la; i++){
            if(a[i] < b[i]) return -1;
            else if(a[i] > b[i]) return 1;
        }
        return 0;
    }
}

int main(){
    int N; cin >> N;
    string nums[N];
    for(int i = 0; i < N; i++) cin >> nums[i];
    int K; cin >> K;

    // get sums with each number replaced with 'Z'
    string sums[36];
    for(int i = 0; i < 36; i++){
        char task = ord((char)(i + '0'));
        string repl[N];
        for(int j = 0; j < N; j++)
            for(int k = 0; k < nums[j].length(); k++)
                if(nums[j][k] == task) repl[j] += 'Z';
                else repl[j] += nums[j][k];
        string s = "0";
        for(const string& rep : repl)
            s = sum(s, rep);
        sums[i] = s;
    }

    // subtract with naive sum to compare
    string naive = "0";
    for(const string& num : nums) naive = sum(naive, num);
    string subs[36];
    for(int i = 0; i < 36; i++) subs[i] = sub(sums[i], naive);

    // find K biggest subtracted sums
    for(int i = 0; i < K; i++) {
        string smax = "0";
        int idx = 0;
        for(int j = 0; j < 36; j++){
            if(compare(subs[j], smax) > 0){
                smax = subs[j];
                idx = j;
            }
        }
        naive = sum(naive, smax);
        subs[idx] = "0";
    }

    cout << naive << endl;
}