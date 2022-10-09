// BOJ 1079 [Mafia]
// Supported by GitHub Copilot

#include <iostream>
using namespace std;

int N, M;
int guilty[16];
int R[16][16];
bool alive[16];

int NIGHT_MAX = 0;
void play(int survivors, int night){
    if(survivors == 1){
        NIGHT_MAX = night;
        return;
    }

    if(survivors % 2){ // day
        // find guilty person
        int gmx = 0, gid = 0;
        for(int i=0; i<N; i++){
            if(alive[i] && guilty[i] > gmx){
                gmx = guilty[i];
                gid = i;
            }
        }

        if(gid == M){ // mafia dies
            NIGHT_MAX = max(NIGHT_MAX, night);
            return;
        }

        // kill guilty person
        alive[gid] = false;
        play(survivors-1, night);
        alive[gid] = true;
    }
    else{ // night
        // simulate each person
        for(int i=0; i<N; i++){
            if(alive[i] && i != M){
                // kill i
                alive[i] = false;
                for(int j=0; j<N; j++) guilty[j] += R[i][j];
                play(survivors-1, night+1);
                for(int j=0; j<N; j++) guilty[j] -= R[i][j];
                alive[i] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++) cin >> guilty[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> R[i][j];
        }
    }
    cin >> M;

    for(int i=0; i<N; i++) alive[i] = true;
    play(N, 0);
    cout << NIGHT_MAX;
}
