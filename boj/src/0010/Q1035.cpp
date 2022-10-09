// BOJ 1035 [Move the Pieces]
// Supported by GitHub Copilot

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

map<int, int> MAP;
int MIN = 15;
bool isBlock(int board, int i, int j) {
    return (board & (1 << (i * 5 + j))) != 0;
}
int setBlock(int board, int i, int j) {
    return board | (1 << (i * 5 + j));
}
int clearBlock(int board, int i, int j) {
    return board & ~(1 << (i * 5 + j));
}

bool visited[5][5];
int floodFill(int board, int i, int j){
    if (i < 0 || i >= 5 || j < 0 || j >= 5) return 0;
    if (!isBlock(board, i, j)) return 0;
    if (visited[i][j]) return 0;
    visited[i][j] = true;
    int ret = 1;
    board = clearBlock(board, i, j);
    ret += floodFill(board, i + 1, j);
    ret += floodFill(board, i - 1, j);
    ret += floodFill(board, i, j + 1);
    ret += floodFill(board, i, j - 1);
    return ret;
}

vector<pair<int, int>> BLOCKS;
void dfs(int board, int depth){
    if (depth >= MIN) return;
    MAP[board] = depth;
    memset(visited, false, sizeof(visited));
    if (floodFill(board, BLOCKS[0].first, BLOCKS[0].second) == BLOCKS.size()) {
        MIN = min(MIN, depth);
        return;
    }
    for (auto & block : BLOCKS) {
        int x = block.first;
        int y = block.second;
        if (x > 0 && !isBlock(board, x - 1, y)) {
            int nextBoard = setBlock(clearBlock(board, x, y), x - 1, y);
            if (MAP.find(nextBoard) == MAP.end() || MAP[nextBoard] > depth + 1) {
                block = {x - 1, y};
                dfs(nextBoard, depth + 1);
                block = {x, y};
            }
        }
        if (x < 4 && !isBlock(board, x + 1, y)) {
            int nextBoard = setBlock(clearBlock(board, x, y), x + 1, y);
            if (MAP.find(nextBoard) == MAP.end() || MAP[nextBoard] > depth + 1) {
                block = {x + 1, y};
                dfs(nextBoard, depth + 1);
                block = {x, y};
            }
        }
        if (y > 0 && !isBlock(board, x, y - 1)) {
            int nextBoard = setBlock(clearBlock(board, x, y), x, y - 1);
            if (MAP.find(nextBoard) == MAP.end() || MAP[nextBoard] > depth + 1) {
                block = {x, y - 1};
                dfs(nextBoard, depth + 1);
                block = {x, y};
            }
        }
        if (y < 4 && !isBlock(board, x, y + 1)) {
            int nextBoard = setBlock(clearBlock(board, x, y), x, y + 1);
            if (MAP.find(nextBoard) == MAP.end() || MAP[nextBoard] > depth + 1) {
                block = {x, y + 1};
                dfs(nextBoard, depth + 1);
                block = {x, y};
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int board = 0;
    for(int i = 0; i < 5; i++){
        string s; cin >> s;
        for(int j = 0; j < 5; j++){
            if (s[j] == '*') {
                board = setBlock(board, i, j);
                BLOCKS.emplace_back(i, j);
            }
        }
    }
    dfs(board, 0);
    cout << MIN;
}
