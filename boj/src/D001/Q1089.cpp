// BOJ 1089 [StartLink Tower]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool bulb[10][5][3] = {
    {{true, true, true}, {true, false, true}, {true, false, true}, {true, false, true}, {true, true, true}},
    {{false, false, true}, {false, false, true}, {false, false, true}, {false, false, true}, {false, false, true}},
    {{true, true, true}, {false, false, true}, {true, true, true}, {true, false, false}, {true, true, true}},
    {{true, true, true}, {false, false, true}, {true, true, true}, {false, false, true}, {true, true, true}},
    {{true, false, true}, {true, false, true}, {true, true, true}, {false, false, true}, {false, false, true}},
    {{true, true, true}, {true, false, false}, {true, true, true}, {false, false, true}, {true, true, true}},
    {{true, true, true}, {true, false, false}, {true, true, true}, {true, false, true}, {true, true, true}},
    {{true, true, true}, {false, false, true}, {false, false, true}, {false, false, true}, {false, false, true}},
    {{true, true, true}, {true, false, true}, {true, true, true}, {true, false, true}, {true, true, true}},
    {{true, true, true}, {true, false, true}, {true, true, true}, {false, false, true}, {true, true, true}}
};

double avg(const vector<string>& bulbs){
    bool ret[10];
    for(bool & i : ret) i = true;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 10; k++){
                if(bulbs[i][j] == '#' && !bulb[k][i][j]){
                    ret[k] = false;
                }
            }
        }
    }

    int s = 0, c = 0;
    for(int i = 0; i < 10; i++){
        if(ret[i]){
            s += i;
            c++;
        }
    }
    if(c == 0) return -1;
    return (double) s / c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> board(5);
    for(int i = 0; i < 5; i++) cin >> board[i];

    double ans = 0;
    int fac = 1;
    vector<string> bulbs(5);
    for(int i = 4*N-4; i >= 0; i -= 4){
        for(int j = 0; j < 5; j++){
            bulbs[j] = board[j].substr(i, 3);
        }
        double val;
        if((val = avg(bulbs)) == -1){
            cout << -1;
            return 0;
        }
        ans += val * fac;
        fac *= 10;
    }
    cout << ans;
}
