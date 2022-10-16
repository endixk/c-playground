// BOJ 1156 [Toys]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;
#define INF INT32_MAX

struct Toys{
    int n, d; // n: number of toys, d: days used
    Toys(int n, int d): n(n), d(d) {}
    void adjust(int x){n -= x;}
};

int D, N1, N2, C1, C2, Tc;
deque<Toys> QA, QB, QC;

int today, treq[100001];
void qa_to_qb(){
    if(QA.empty()) return;
    Toys t = QA.front();
    while(today - t.d >= N1){
        QB.emplace_back(t.n, t.d);
        QA.pop_front();
        if(QA.empty()) return;
        t = QA.front();
    }
}
void qb_to_qc(){
    if(QB.empty()) return;
    Toys t = QB.front();
    while(today - t.d >= N2){
        QC.emplace_back(t.n, t.d);
        QB.pop_front();
        if(QB.empty()) return;
        t = QB.front();
    }
}

int cost(int ntoy){
    QA = deque<Toys>(), QB = deque<Toys>(), QC = deque<Toys>();
    int c = ntoy * (Tc - C2);
    QA.emplace_back(ntoy, -999999);

    for(today = 0; today < D; today++){
        qa_to_qb(); qb_to_qc();
        int req = treq[today];

        // use QC first
        while(req > 0 && !QC.empty()){
            Toys* t = &QC.front();
            if(t->n <= req){
                c += t->n * C2;
                req -= t->n;
                QC.pop_front();
            }
            else{
                c += req * C2;
                t->adjust(req);
                req = 0;
            }
        }
        // then use QB
        while(req > 0 && !QB.empty()){
            Toys* t = &QB.back();
            if(t->n <= req){
                c += t->n * C1;
                req -= t->n;
                QB.pop_back();
            }
            else{
                c += req * C1;
                t->adjust(req);
                req = 0;
            }
        }
        if(req > 0) return INF;
        QA.emplace_back(treq[today], today);
    }
    return c;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // input
    cin >> D >> N1 >> N2 >> C1 >> C2 >> Tc;
    int rsum = 0;
    for(int i = 0; i < D; i++) {
        cin >> treq[i];
        rsum += treq[i];
    }

    // adjust input
    if(N1 > N2) swap(N1, N2), swap(C1, C2);
    if(C1 < C2) C2 = C1;

    // ternary search
    int l = 0, r = rsum+1, ans = INF;
    while(true){
        if(r - l <= 2){
            for(int i = l; i <= r; i++) ans = min(ans, cost(i));
            break;
        }
        int m1 = (l*2+r)/3, m2 = (l+r*2)/3;
        int c1 = cost(m1), c2 = cost(m2);
        if(c1 > c2) l = m1;
        else r = m2;
    }
    cout << ans;
}
