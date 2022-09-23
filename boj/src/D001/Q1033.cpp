// Cocktail
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
using namespace std;

struct node {
    int vol = -1;
    vector<int> edges;
};

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int N;
    cin >> N;

    vector<node> nodes(N);
    for(int i = 1; i < N; i++){
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        if(nodes[a].vol < 0) nodes[a].vol = 1;
        if(nodes[b].vol < 0) nodes[b].vol = 1;

        int gvol = gcd(nodes[a].vol, nodes[b].vol);
        int afac = nodes[b].vol / gvol * p, bfac = nodes[a].vol / gvol * q;
        int gfac = gcd(afac, bfac);

        // DFS from a to update volumes
        vector<bool> visited(N, false);
        vector<int> stack;
        stack.push_back(a);
        while(!stack.empty()){
            int cur = stack.back();
            stack.pop_back();
            if(visited[cur]) continue;
            visited[cur] = true;
            nodes[cur].vol *= afac / gfac;
            for(int next : nodes[cur].edges)
                if(!visited[next]) stack.push_back(next);
        }

        // DFS from b to update volumes
        visited.assign(N, false);
        stack.push_back(b);
        while(!stack.empty()){
            int cur = stack.back();
            stack.pop_back();
            if(visited[cur]) continue;
            visited[cur] = true;
            nodes[cur].vol *= bfac / gfac;
            for(int next : nodes[cur].edges)
                if(!visited[next]) stack.push_back(next);
        }

        nodes[a].edges.push_back(b);
        nodes[b].edges.push_back(a);
    }
    for(int i = 0; i < N; i++) cout << nodes[i].vol << ' ';
    cout << endl;
}