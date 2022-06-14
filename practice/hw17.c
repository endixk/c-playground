#include <stdio.h>

void P1(){
    int num;
    printf("Enter any natural number:");
    scanf("%d", &num);
    printf("ans:%d\n", num % 3 == 0 ? 1 : 0);
}

void P2(){
    char ch;
    printf("Enter any alphabet:");
    scanf("%c", &ch);
    for(; ch >= 'A'; ch--){
        printf("%c", ch);
    }
}

int P3(int n){
    int x = 1, y = 1;
    for(int i = 1; i < n; i++){
        int t = y;
        y += x;
        x = t;
    }
    return y;
}

int P4(int n){
    int r = 0, f = 1;
    while(n > 0){
        r += (n % 4) * f;
        f *= 10;
        n /= 4;
    }
    return r;
}