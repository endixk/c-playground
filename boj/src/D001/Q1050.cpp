// BOJ 1050 [Potion]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> ret;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, delimiter)) ret.push_back(temp);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    map<string, int> ingr;
    for (int i = 0; i < N; i++) {
        string name;
        int num;
        cin >> name >> num;
        ingr[name] = num;
    }

    vector<pair<string, vector<pair<string, int>>>> recipe;
    for (int i = 0; i < M; i++) {
        string eq; cin >> eq;
        vector<string> eqs = split(eq, '=');

        if(ingr.find(eqs[0]) == ingr.end()) ingr[eqs[0]] = -1;
        vector<string> parts = split(eqs[1], '+');
        vector<pair<string, int>> pvec;
        for(const string& part : parts){
            int num = stoi(part.substr(0, 1));
            string name = part.substr(1);
            if(ingr.find(name) == ingr.end()) ingr[name] = -1;
            pvec.emplace_back(name, num);
        }
        recipe.emplace_back(eqs[0], pvec);
    }

    while(true) {
        bool conv = true;
        for (const pair<string, vector<pair<string, int>>> &r: recipe) {
            // check unreachable ingredient
            bool reach = true;
            for(const pair<string, int> &p: r.second){
                if(ingr[p.first] == -1){
                    reach = false;
                    break;
                }
            }
            if(!reach) continue;

            // calculate cost
            long long cost = 0;
            for(const pair<string, int> &p: r.second){
                cost += (long long) ingr[p.first] * p.second;
            }
            int c = (cost > 1000000000) ? 1000000001 : int(cost);

            // update cost
            if(ingr[r.first] == -1 || ingr[r.first] > c){
                ingr[r.first] = c;
                conv = false;
            }
        }
        if(conv) break;
    }

    // print cost of LOVE
    if(ingr.find("LOVE") == ingr.end() || ingr["LOVE"] == -1) cout << -1;
    else cout << ingr["LOVE"] << '\n';
}