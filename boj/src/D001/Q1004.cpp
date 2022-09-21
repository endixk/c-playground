// Le Petit Prince

#include <iostream>
#include <vector>
using namespace std;

struct Circle {
    int x, y, r, depth;
    Circle *parent;
    vector<Circle> enclose;
};

void push(Circle &c, Circle &d){
    Circle *enc = nullptr;
    for(int i = 0; i < c.enclose.size(); i++){

    }
}

int main(){
    int T;
    cin >> T;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    struct Circle world = {0, 0, 1000000000, 0, nullptr};
    for(int i = 0; i < T; i++){
        int x, y, r;
        cin >> x >> y >> r;
    }
}