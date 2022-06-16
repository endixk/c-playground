#include <stdio.h>
#include <stdlib.h>
#include "hw17.h"

#define HWNO 17

void hw17(int q, char** args){
    char* ptr;
    switch(q){
        case 1:
            P1();
            break;
        case 2:
            P2();
            break;
        case 3:
            for(int i = 1; i <= strtol(args[0], &ptr, 10); i++){
                printf("fib(%d) = %d\n", i, P3(i));
            }
            break;
        case 4:
            for(int i = 1; i <= strtol(args[0], &ptr, 10); i++){
                printf("%d_(4) = %d\n", i, P4(i));
            };
            break;
        default: return;
    }
}

int main() {
    char* arg = "10";
    char* args[] = {arg};

    switch(HWNO){
        case 17: hw17(4, args); break;

    }
    return 0;
}
