// BOJ 1169 [Displaying Squares]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct Square{
    int x, w, n;
    Square(int x, int w, int n): x(x), w(w), n(n) {}
    bool operator<(const Square& rhs) const {
        return w > rhs.w;
    }
};

vector<Square> squares;
vector<pair<int,int>> covered;
void update(int l, int r){
    for(int i=0; i<covered.size(); i++){
        if(i < covered.size() - 1){
            if(covered[i].second == l && covered[i+1].first == r){
                covered[i].second = covered[i+1].second;
                covered.erase(covered.begin() + i + 1);
                return;
            }
        }
        if(covered[i].second == l){
            covered[i].second = r;
            return;
        }
        if(covered[i].first == r){
            covered[i].first = l;
            return;
        }
    }
    covered.emplace_back(l, r);
    sort(covered.begin(), covered.end());
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        int w; cin >> w;
        int x = w;
        for(int j=0; j<i; j++){
            x = max(x, squares[j].x + 2 * min(squares[j].w, w));
        }
        squares.emplace_back(x, w, i+1);
    }
    sort(squares.begin(), squares.end());

    vector<int> res;
    for(Square s : squares){
        int l = s.x - s.w, r = s.x + s.w;
        for(auto [cl, cr] : covered){
            if(cr < l || cl > r) continue;
            if(cr <= r) l = cr;
            if(cl >= l) r = cl;
            if(cr >= r && cl <= l) l = r;
            if(l >= r) break;
        }
        if(l < r) {
            update(l, r);
            res.push_back(s.n);
        }
    }

    sort(res.begin(), res.end());
    for(int r : res) cout << r << ' ';
}
