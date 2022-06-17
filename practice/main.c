#include <stdio.h>
#include <stdlib.h>
#include "hw17.h"
#include "hw18.h"

#define HWNO 18

void hw17(int q, char** args){
    char* ptr;
    switch(q){
        case 1:
            P17_1();
            break;
        case 2:
            P17_2();
            break;
        case 3:
            for(int i = 1; i <= strtol(args[0], &ptr, 10); i++){
                printf("fib(%d) = %d\n", i, P17_3(i));
            }
            break;
        case 4:
            for(int i = 1; i <= strtol(args[0], &ptr, 10); i++){
                printf("%d_(4) = %d\n", i, P17_4(i));
            };
            break;
        default: return;
    }
}

void hw18(int q, char** args){
    char* ptr;
    switch(q){
        case 1: printf("%d\n", P18_1(strtol(args[0], &ptr, 10))); break;
        case 2: printf("%d\n", P18_2(strtol(args[0], &ptr, 10))); break;
        case 3: printf("%d\n", P18_3(strtol(args[0], &ptr, 10))); break;
        case 4: printf("%d\n", P18_4(strtol(args[0], &ptr, 10))); break;
    }
}

int main() {
    char* arg = "15";
    char* args[] = {arg};

    switch(HWNO){
        case 17: hw17(4, args); break;
        case 18: hw18(4, args); break;
    }
    return 0;
}
