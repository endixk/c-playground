// BOJ 9250 [String Set]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* next[26]{};
    Trie* fail;
    bool isEnd;
    Trie(){
        fill(next, next+26, nullptr);
        fail = nullptr;
        isEnd = false;
    }
    void insert(const string& s){
        if(s.empty()){
            isEnd = true;
            return;
        }
        int idx = s[0] - 'a';
        if(!next[idx]) next[idx] = new Trie();
        next[idx]->insert(s.substr(1));
    }
};

void buildFail(Trie* root){
    queue<Trie*> q;
    root->fail = root;
    q.push(root);
    while(!q.empty()){
        Trie* cur = q.front();
        q.pop();
        for(int i = 0; i < 26; ++i){
            Trie* nxt = cur->next[i];
            if(!nxt) continue;
            if(cur == root) nxt->fail = root;
            else{
                Trie* tmp = cur->fail;
                while(tmp != root && !tmp->next[i]) tmp = tmp->fail;
                if(tmp->next[i]) tmp = tmp->next[i];
                nxt->fail = tmp;
            }
            nxt->isEnd |= nxt->fail->isEnd;
            q.push(nxt);
        }
    }
}

bool find(const string& s, Trie* root){
    Trie* cur = root;
    for(char c : s){
        int idx = c - 'a';
        while(cur != root && !cur->next[idx]) cur = cur->fail;
        if(cur->next[idx]) cur = cur->next[idx];
        if(cur->isEnd) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, Q;

    cin >> N;
    Trie* root = new Trie();
    while(N--){
        string s;
        cin >> s;
        root->insert(s);
    }
    buildFail(root);

    cin >> Q;
    while(Q--) {
        string s;
        cin >> s;
        cout << (find(s, root) ? "YES" : "NO") << '\n';
    }
}
