// Le Petit Prince

#include <iostream>
#include <vector>
using namespace std;

struct Circle {
    int x, y, r, depth;
    Circle *parent;
    vector<Circle> enclose;
};

// 0 : not enclosed
// 1 : x encloses y
// -1: y encloses x
int compare(Circle &x, Circle &y){
    int dx = x.x - y.x, dy = x.y - y.y;
    int d = dx * dx + dy * dy;
    int r = x.r + y.r;
    if(d > r * r) return 0;
    if(d + y.r * y.r < x.r * x.r) return 1;
    if(d + x.r * x.r < y.r * y.r) return -1;
    return 0;
}

void increment(Circle &c){
    c.depth++;
    for(auto & i : c.enclose){
        increment(i);
    }
}

struct Circle common_ancestor(Circle x, Circle y){
    if(x.depth > y.depth){
        return common_ancestor(y, x);
    }
    while(x.depth < y.depth){
        y = *y.parent;
    }
    while(x.x != y.x || x.y != y.y || x.r != y.r){
        x = *x.parent;
        y = *y.parent;
    }
    return x;
}

void push(Circle &parent, Circle &child){
    int enc = -1;
    for(int i = 0; i < parent.enclose.size(); i++){
        int cmp = compare(parent.enclose[i], child);
        if(cmp == 1){
            enc = i;
            break;
        }
    }
    if(enc == -1){
        for(int i = 0; i < parent.enclose.size(); i++){
            int cmp = compare(parent.enclose[i], child);
            if(cmp == -1){
                enc = i;
                break;
            }
        }
        if(enc >= 0){
            child.enclose.push_back(parent.enclose[enc]);
            increment(child.enclose.back());
            child.enclose.back().parent = &child;
            parent.enclose.erase(parent.enclose.begin() + enc);
        }
        child.parent = &parent;
        child.depth = parent.depth + 1;
        parent.enclose.push_back(child);
    } else {
        push(parent.enclose[enc], child);
    }
}

int main(){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;
        struct Circle world = {0, 0, 1000000000, 0, nullptr};
        for (int i = 0; i < n; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            Circle c = {x, y, r, 0, nullptr};
            push(world, c);
        }

        struct Circle st = {x1, y1, 0, 0, nullptr};
        struct Circle ed = {x2, y2, 0, 0, nullptr};
        push(world, st);
        push(world, ed);

        struct Circle ca = common_ancestor(st, ed);
        cout << st.depth + ed.depth - 2 * ca.depth - 2 << endl;
    }
    return 0;
}