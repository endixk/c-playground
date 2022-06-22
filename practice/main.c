#include <stdio.h>
#include <stdlib.h>

#include "hw17.h"
#include "hw18.h"
#include "hw19.h"

#define HWNO 19

void hw17(int q, char **argv){
    switch(q){
        case 1:
            P17_1();
            break;
        case 2:
            P17_2();
            break;
        case 3:
            for(int i = 1; i <= atoi(argv[0]); i++){
                printf("fib(%d) = %d\n", i, P17_3(i));
            }
            break;
        case 4:
            for(int i = 1; i <= atoi(argv[0]); i++){
                printf("%d_(4) = %d\n", i, P17_4(i));
            }
            break;
        default: return;
    }
}

void hw18(int q, char **argv){
    switch(q){
        case 1: printf("%d\n", P18_1(atoi(argv[0]))); break;
        case 2: printf("%d\n", P18_2(atoi(argv[0]))); break;
        case 3: printf("%d\n", P18_3(atoi(argv[0]))); break;
        case 4: printf("%d\n", P18_4(atoi(argv[0]))); break;
        default: return;
    }
}

void hw19(int q, int argc, char** argv){
    if(q == 1){
        int iargv[argc];
        for(int i = 0; i < argc; i++) iargv[i] = atoi(argv[i]);
        char* res = P19_1(argc, iargv);
        printf("%s\n", res);
        free(res);
    }
    else if(q == 2){
        char* res = P19_2(argv[0]);
        printf("%s\n", res);
        free(res);
    }
    else if(q == 3){
        char cargv[argc];
        for(int i = 0; i < argc; i++) cargv[i] = argv[i][0];
        char* res = P19_3(argc, cargv);
        printf("%s\n", res);
        free(res);
    }
    else if(q == 4){
        int iargv[argc];
        for(int i = 0; i < argc; i++) iargv[i] = atoi(argv[i]);
        char* res = P19_4(argc, iargv);
        printf("%s\n", res);
        free(res);
    }
    else if(q == 5){
        char x = argv[0][0], y = argv[1][0];
        char *ptrx = &x, *ptry = &y;
        char *ptr = P19_5(ptrx, ptry);
        printf("%c,%c,%c\n", *ptrx, *ptry, *ptr);
    }
}

int main() {
    char *arg = "15";
    int argc = 2;
    char *argv[] = {"0", "1"};

    switch(HWNO){
        case 17: hw17(4, argv); break;
        case 18: hw18(4, argv); break;
        case 19: hw19(5, argc, argv); break;
    }
    return 0;
}
