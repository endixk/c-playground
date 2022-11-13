// BOJ 17081 [RPG Extreme]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

class Monster {
public:
    string name;
    int HP, MHP, ATK, DEF, EXP;
    bool isBoss;
    Monster(string name, int MHP, int ATK, int DEF, int EXP, bool isBoss) :
    name(std::move(name)), MHP(MHP), ATK(ATK), DEF(DEF), EXP(EXP), isBoss(isBoss) {HP = MHP;}

    bool takeDamage(int dmg){
        HP -= dmg;
        return HP > 0;
    }
};

map<string,int> accList = {{"HR", 1}, {"RE", 2}, {"CO", 3}, {"EX", 4}, {"DX", 5}, {"HU", 6}, {"CU", 7}};
class Item {
public:
    char type;
    int value;
    Item(char type, int value) : type(type), value(value) {}
};

class Player {
public:
    // stats
    int HP = 20, MHP = 20, ATK = 2, DEF = 2;
    int LV = 1, EXP = 0;
    void levelUp(){
        LV++;
        MHP += 5;
        ATK += 2;
        DEF += 2;
        HP = MHP;
    }
    void gainEXP(int exp){
        if(isEquipped("EX")) exp = (int)(1.2 * exp);
        EXP += exp;
        if(EXP >= LV * 5){
            EXP = 0;
            levelUp();
        }
    }
    void gainHP(int hp){
        HP += hp;
        if(HP > MHP) HP = MHP;
    }
    bool takeDamage(int dmg){
        HP -= dmg;
        if(HP <= 0) HP = 0;
        return HP > 0;
    }

    // equipments
    int WPN = 0, ARM = 0;
    int ACC[4] = {0, 0, 0, 0};
    void equipAccessory(int acc){
        // already equipped
        if(find(ACC, ACC+4, acc) != ACC+4) return;

        // find empty slot
        int *slot = find(ACC, ACC+4, 0);
        if(slot == ACC+4) return;
        *slot = acc;
    }
    void unequipAccessory(int acc){
        int *slot = find(ACC, ACC+4, acc);
        if(slot == ACC+4) return;
        *slot = 0;
    }
    void unequipAccessory(const string& acc){
        unequipAccessory(accList[acc]);
    }
    bool isEquipped(int acc){
        return find(ACC, ACC+4, acc) != ACC+4;
    }
    bool isEquipped(const string& acc){
        return isEquipped(accList[acc]);
    }

    void equipItem(Item& item){
        switch(item.type){
            case 'W':
                WPN = item.value;
                break;
            case 'A':
                ARM = item.value;
                break;
            case 'O':
                equipAccessory(item.value);
                break;
        }
    }

    // resurrection
    bool resurrect(){
        if(!isEquipped("RE")) return false;

        unequipAccessory("RE");
        HP = MHP;
        return true;
    }

    // spike damage
    bool spike(){
        int dmg = isEquipped("DX") ? 1 : 5;
        return takeDamage(dmg);
    }

    // battle with monster
    bool battle(Monster& monster){
        if(isEquipped("HU") && monster.isBoss) HP = MHP;
        bool first = true;
        while(true){
            // player's turn
            int atk = ATK + WPN;
            if(first){
                if(isEquipped("CO")){
                    if(isEquipped("DX")) atk *= 3;
                    else atk *= 2;
                }
            }
            int dmg = max(1, atk - monster.DEF);
            if(!monster.takeDamage(dmg)) break;

            // monster's turn
            dmg = max(1, monster.ATK - DEF - ARM);
            if(first && isEquipped("HU") && monster.isBoss) dmg = 0;
            if(!takeDamage(dmg)) {
                monster.HP = monster.MHP;
                return false;
            }

            first = false;
        }

        if(isEquipped("HR")) gainHP(3);
        gainEXP(monster.EXP);
        return true;
    }
};

int N, M, X, Y, SX, SY;
char board[100][100];
int mmap[100][100], imap[100][100];
vector<Monster> monsters;
vector<Item> items;
Player player;
string moves;

int turns = 0;
string statusMsg = "Press any key to continue.";
void printStatus(){
    // print board
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cout << board[i][j];
        }
        cout << '\n';
    }

    // print status
    cout << "Passed Turns : " << turns << '\n';
    cout << "LV : " << player.LV << '\n';
    cout << "HP : " << player.HP << '/' << player.MHP << '\n';
    cout << "ATT : " << player.ATK << '+' << player.WPN << '\n';
    cout << "DEF : " << player.DEF << '+' << player.ARM << '\n';
    cout << "EXP : " << player.EXP << '/' << player.LV * 5 << '\n';
    cout << statusMsg << '\n';
}

char buffer = '.';
void play(){
    for(char c : moves){
        turns++;
        int nx = X, ny = Y;
        switch(c){
            case 'L': ny--; break;
            case 'R': ny++; break;
            case 'U': nx--; break;
            case 'D': nx++; break;
        }
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) nx = X, ny = Y;
        if(board[nx][ny] == '#') nx = X, ny = Y;

        // move
        if(board[nx][ny] != '@'){
            board[X][Y] = buffer;
            buffer = board[nx][ny];
            board[nx][ny] = '@';
            X = nx, Y = ny;
        }

        // process buffer
        if(buffer == '.') continue;
        else if(buffer == '^'){ // spike trap
            if(!player.spike()){
                if(player.resurrect()){
                    board[X][Y] = buffer;
                    buffer = board[SX][SY];
                    board[SX][SY] = '@';
                    X = SX, Y = SY;
                }
                else{
                    board[X][Y] = buffer;
                    statusMsg = "YOU HAVE BEEN KILLED BY SPIKE TRAP..";
                    return;
                }
            }
        }
        else if(buffer == '&' || buffer == 'M'){ // monster
            Monster& monster = monsters[mmap[X][Y]];
            if(!player.battle(monster)){
                if(player.resurrect()){
                    board[X][Y] = buffer;
                    buffer = board[SX][SY];
                    board[SX][SY] = '@';
                    X = SX, Y = SY;
                }
                else{
                    board[X][Y] = buffer;
                    statusMsg = "YOU HAVE BEEN KILLED BY " + monster.name + "..";
                    return;
                }
            }
            else {
                buffer = '.';
                if(monster.isBoss){
                    statusMsg = "YOU WIN!";
                    return;
                }
            }
        }
        else if(buffer == 'B'){ // item box
            Item& item = items[imap[X][Y]];
            player.equipItem(item);
            buffer = '.';
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;
    int bx = 0, by = 0; // boss position
    int mcnt = 0, icnt = 0;
    for(int i=0; i<N; ++i){
        string s; cin >> s;
        for(int j=0; j<M; ++j){
            board[i][j] = s[j];
            if(s[j] == '@') SX = X = i, SY = Y = j;
            if(s[j] == 'M') bx = i, by = j, mcnt++;
            if(s[j] == '&') mcnt++;
            if(s[j] == 'B') icnt++;
        }
    }

    cin >> moves;
    for(int i=0; i<mcnt; ++i){
        string name; int x, y, hp, atk, def, exp;
        cin >> x >> y >> name >> atk >> def >> hp >> exp;
        mmap[--x][--y] = i;
        bool isBoss = (x == bx && y == by);
        monsters.emplace_back(name, hp, atk, def, exp, isBoss);
    }
    for(int i=0; i<icnt; ++i){
        char type; int x, y, v = 0; string value;
        cin >> x >> y >> type >> value;
        switch(type){
            case 'W': case 'A':
                v = stoi(value);
                break;
            case 'O':
                v = accList[value];
                break;
        }
        imap[--x][--y] = i;
        items.emplace_back(type, v);
    }

    play();
    printStatus();
}
