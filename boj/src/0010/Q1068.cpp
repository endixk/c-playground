// BOJ 1068 [Tree]
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // build tree
    int N; cin >> N;
    vector<pair<int, vector<int>>> tree(N);
    int rid = -1;
    for (int i = 0; i < N; i++) {
        tree[i].first = i;
        int p; cin >> p;
        if (p != -1) tree[p].second.push_back(i);
        else rid = i;
    }

    // remove node
    int D; cin >> D;
    if (D == rid) {
        cout << 0 << '\n';
        return 0;
    }
    for(pair<int, vector<int>> &node : tree){
        for(int i = 0; i < node.second.size(); i++){
            if(node.second[i] == D){
                node.second.erase(node.second.begin() + i);
                break;
            }
        }
    }

    // count leaf
    int cnt = 0;
    stack<int> s;
    s.push(rid);
    while(!s.empty()){
        int id = s.top(); s.pop();
        if(tree[id].second.empty()) cnt++;
        else for(int child : tree[id].second) s.push(child);
    }
    cout << cnt << '\n';
}
