// BOJ 1055 [Endless]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

string Q, B;
long long qlen, blen;
long long ccnt, dcnt; // character count, dollar count

char endless(long long loc, long long bsize){
    if(bsize < qlen) return Q[loc-1];

    long long offset = 0;
    for(long long i = 0; i < blen; i++){
        if(B[i] == '$'){
            if(loc > offset && loc <= offset + bsize) return endless(loc - offset, bsize > ccnt ? (bsize - ccnt) / dcnt : 0);
            else offset += bsize;
        }
        else{
            if(loc == offset + 1) return B[i];
            else offset++;
        }
    }
    return '-';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q >> B;
    qlen = Q.length(), blen = B.length();

    ccnt = dcnt = 0;
    for(const char &c : B){
        if(c == '$') dcnt++;
        else ccnt++;
    }

    long long e, x, y; cin >> e >> x >> y;
    if(dcnt > 1){
        // get maximum bsize
        long long bsize = qlen;
        for(int i = 0; i < e; i++){
            if(bsize >= y) break;
            bsize = bsize * dcnt + ccnt;
        }

        for(long long loc = x; loc <= y; loc++)
            if(loc > bsize) cout << '-';
            else cout << endless(loc, bsize);
    }
    else{
        string b;
        for(const char &c : B) if(c != '$') b += c;

        for(long long loc = x; loc <= y; loc++){
            if(loc <= qlen) cout << Q[loc-1];
            else if(loc > qlen + ccnt * e) cout << '-';
            else cout << b[(loc - qlen - 1) % ccnt];
        }
    }
    cout << '\n';
}
