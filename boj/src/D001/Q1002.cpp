// Turret

#include <stdio.h>

int intersect(int x1, int y1, int r1, int x2, int y2, int r2){
    int d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    int rsum = (r1+r2)*(r1+r2);
    int rsub = (r1-r2)*(r1-r2);
    if(d == 0 && rsub == 0) return -1;
    if(d == rsum || d == rsub) return 1;
    if(d < rsum && d > rsub) return 2;
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        printf("%d\n", intersect(x1, y1, r1, x2, y2, r2));
    }
}