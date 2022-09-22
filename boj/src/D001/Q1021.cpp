// Rotating queue
// Supported by GitHub Copilot

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int pop[M];
    for(int i = 0; i < M; i++)
        cin >> pop[i];

    vector<int> v;
    for(int i = 1; i <= N; i++)
        v.push_back(i);

    int rotation = 0, ptr = 0;
    for(int i = 0; i < M; i++){
        int target = pop[i];
        int loc;
        for(loc = 0; v[loc] != target; loc++);

        int dist = loc - ptr;
        if(dist < 0) dist += v.size();
        if(dist > v.size() - dist) dist = v.size() - dist;
        rotation += dist;

        ptr = loc;
        v.erase(v.begin() + loc);
    }

    cout << rotation << endl;
}