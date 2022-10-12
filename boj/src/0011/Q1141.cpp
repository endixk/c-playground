// BOJ 1141 [Prefix]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

bool prefix(const string& a, const string& b){
    if(a.size() > b.size()) return false;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    string arr[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N,
         [](const string& a, const string& b){return a.size() > b.size(); });

    vector<string> v;
    for(const string& s : arr){
        bool flag = true;
        for(const string& t : v){
            if(prefix(s, t)){
                flag = false;
                break;
            }
        }
        if(flag) v.push_back(s);
    }
    cout << v.size();
}
