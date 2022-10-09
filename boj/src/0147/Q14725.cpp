// BOJ 14725 [Ant Tunnel]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    vector<Node*> children;
};

Node* ROOT;
void push(Node *node, queue<string> &q){
    if(q.empty()) return;
    string name = q.front();
    q.pop();

    for(auto child : node->children){
        if(child->name == name){
            push(child, q);
            return;
        }
    }

    Node *newNode = new Node();
    newNode->name = name;
    int loc = 0;
    for(; loc < node->children.size() && node->children[loc]->name < name; loc++);
    node->children.insert(node->children.begin() + loc, newNode);
    push(newNode, q);
}

void dfs(Node *node, int depth) {
    for (int i = 0; i < depth; i++) cout << "--";
    cout << node->name << '\n';
    for (auto child: node->children) dfs(child, depth + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    ROOT = new Node();
    while(N--){
        int K; cin >> K;
        queue<string> q;
        while(K--){
            string name; cin >> name;
            q.push(name);
        }
        push(ROOT, q);
    }

    for(auto child : ROOT->children) dfs(child, 0);
}
