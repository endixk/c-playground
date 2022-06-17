#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int hanoi(char src, char tmp, char dst, int cnt){
    if(cnt == 1){
        printf("DISK %d : [%c->%c]\n", cnt, src, dst);
        return 1;
    }

    int r = 1;
    r += hanoi(src, dst, tmp, cnt-1);
    printf("DISK %d : [%c->%c]\n", cnt, src, dst);
    r += hanoi(tmp, src, dst, cnt-1);
    return r;
}

int P18_1(int n){
    return hanoi('A', 'B', 'C', n);
}

int P18_2(int n){
    int r = 0;
    while(n > 0){
        r += n % 10;
        n /= 10;
    }
    return r;
}

int P18_3(int n){
    int size = n > INT_MAX / 2 ? INT_MAX : n*2;
    bool gen[size < 100 ? 100 : size];
    for(int i = 1; i <= sizeof gen / sizeof(bool); i++) gen[i] = false;
    for(int i = 1; i <= n; i++){
        if(gen[i]) continue;
        int g = i;
        while(g <= n){
            g += P18_2(g);
            gen[g] = true;
        }
    }
    for(int i = n+1; i <= sizeof gen / sizeof(bool); i++) {
        if (!gen[i]) return i;
        else gen[i + P18_2(i)] = true;
    }
    return -1;
}

int P18_4(int n){
    int divisors[n+1], i, j;
    for(i = 0; i <= n; i++)
        divisors[i] = 0;

    for(i = 2; i <= n; i++){
        int x = i, d = 2;
        int sub_divisors[n+1];
        for(j = 0 ; j <= n; j++)
            sub_divisors[j] = 0;

        while(x != 1){
            int dcnt = 0;
            while(x % d == 0){
                x /= d;
                dcnt++;
            }
            sub_divisors[d] = dcnt;
            d++;
        }

        for(j = 0; j <= n; j++)
            if(sub_divisors[j] > divisors[j])
                divisors[j] = sub_divisors[j];
    }

    int r = 1;
    for(i = 2; i <= n; i++)
        for(j = 0; j < divisors[i]; j++)
            r *= i;

    return r;
}