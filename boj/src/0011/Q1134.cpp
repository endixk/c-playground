// BOJ 1134 [Equation]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

vector<int> digit = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

// return valid digits
vector<int> vd(const vector<int>& v, int len, int mag){
    vector<int> ret;
    if(v[mag] != -1) ret = {v[mag]};
    else{
        ret = digit;
        if(mag == len-1 && mag > 0) ret.pop_back();
    }
    return ret;
}

// compare two vectors
int compare(const vector<int>& a, const vector<int>& b){
    if(a.size() > b.size()) return 1;
    if(a.size() < b.size()) return -1;
    for(int i=(int)a.size(); i>0; i--){
        if(a[i-1] > b[i-1]) return 1;
        if(a[i-1] < b[i-1]) return -1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // parse input
    string eq; cin >> eq;
    int pi = (int)eq.find('+'), ei = (int)eq.find('=');
    string A = eq.substr(0, pi), B = eq.substr(pi+1, ei-pi-1), C = eq.substr(ei+1);

    // create arrays by padding leading zeros
    int lA = (int)A.length(), lB = (int)B.length(), lC = (int)C.length();
    if(lC > max(lA, lB) + 1 || lC < min(lA, lB)){
        cout << -1;
        return 0;
    }
    int maxL = max({lA, lB, lC});
    vector<int> dA(maxL), dB(maxL), dC(maxL);
    for (int i = 0; i < maxL; i++) {
        dA[i] = i < lA ? (A[lA-i-1] == '?' ? -1 : A[lA-i-1]-'0') : 0;
        dB[i] = i < lB ? (B[lB-i-1] == '?' ? -1 : B[lB-i-1]-'0') : 0;
        dC[i] = i < lC ? (C[lC-i-1] == '?' ? -1 : C[lC-i-1]-'0') : 0;
    }

    // bottom-up, keep best with and without carry
    vector<int> coA, coB, coC; // with carry
    vector<int> cxA, cxB, cxC; // without carry
    for (int i = 0; i < maxL; i++) {
        // get valid digits
        vector<int> va = vd(dA, lA, i), vb = vd(dB, lB, i), vc = vd(dC, lC, i);

        // try all combinations
        vector<int> next_coA, next_coB, next_coC;
        vector<int> next_cxA, next_cxB, next_cxC;
        for(int a : va){
            for(int b : vb){
                for(int c : vc){
                    // produced with carry, producing carry
                    if(i > 0 && a+b+1 == c+10){
                        vector<int> tmpA = coA, tmpB = coB, tmpC = coC;
                        tmpA.push_back(a); tmpB.push_back(b); tmpC.push_back(c);
                        if( (compare(tmpC, next_coC) > 0) ||
                            (compare(tmpC, next_coC) == 0 && compare(tmpA, next_coA) > 0)){
                            next_coA = tmpA; next_coB = tmpB; next_coC = tmpC;
                        }
                    }
                    // produced with carry, not producing carry
                    if(i > 0 && a+b+1 == c){
                        vector<int> tmpA = coA, tmpB = coB, tmpC = coC;
                        tmpA.push_back(a); tmpB.push_back(b); tmpC.push_back(c);
                        if( (compare(tmpC, next_cxC) > 0) ||
                            (compare(tmpC, next_cxC) == 0 && compare(tmpA, next_cxA) > 0)){
                            next_cxA = tmpA; next_cxB = tmpB; next_cxC = tmpC;
                        }
                    }
                    // produced without carry, producing carry
                    if(a+b == c+10){
                        vector<int> tmpA = cxA, tmpB = cxB, tmpC = cxC;
                        tmpA.push_back(a); tmpB.push_back(b); tmpC.push_back(c);
                        if( (compare(tmpC, next_coC) > 0) ||
                            (compare(tmpC, next_coC) == 0 && compare(tmpA, next_coA) > 0)){
                            next_coA = tmpA; next_coB = tmpB; next_coC = tmpC;
                        }
                    }
                    // produced without carry, not producing carry
                    if(a+b == c){
                        vector<int> tmpA = cxA, tmpB = cxB, tmpC = cxC;
                        tmpA.push_back(a); tmpB.push_back(b); tmpC.push_back(c);
                        if( (compare(tmpC, next_cxC) > 0) ||
                            (compare(tmpC, next_cxC) == 0 && compare(tmpA, next_cxA) > 0)){
                            next_cxA = tmpA; next_cxB = tmpB; next_cxC = tmpC;
                        }
                    }
                }
            }
        }

        // update
        coA = next_coA; coB = next_coB; coC = next_coC;
        cxA = next_cxA; cxB = next_cxB; cxC = next_cxC;
    }

    if(cxA.size() != maxL || cxB.size() != maxL || cxC.size() != maxL){
        cout << -1;
        return 0;
    }

    // print answer
    for(int i=lA; i>0; i--) cout << cxA[i-1];
    cout << '+';
    for(int i=lB; i>0; i--) cout << cxB[i-1];
    cout << '=';
    for(int i=lC; i>0; i--) cout << cxC[i-1];
}
