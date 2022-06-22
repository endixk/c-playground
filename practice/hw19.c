#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *P19_1(int iargc, int *iargv){
    char *alphabet[] = {"ABCD", "EFGH", "IJKL", "MNOP"};
    char *res = (char *) calloc(iargc, sizeof(char));

    for(int i = 0; i < iargc; i++){
        res[i] = alphabet[iargv[i]][i];
    }

    return res;
}

char *P19_2(char *str){
    int len = strlen(str);
    char *res = (char *) calloc(len, sizeof(char));

    for(int i = 0; i < len; i++){
        if(('a' <= str[i]) && (str[i] <= 'z'))
            res[i] = str[i] + 'A' - 'a';
        else if(('A' <= str[i]) && (str[i] <= 'Z'))
            res[i] = str[i] + 'a' - 'A';
        else
            res[i] = str[i];
    }

    return res;
}

// return x > y
bool compare(char x, char y){
    char lx = x <= 'Z' ? x + 'a' - 'A' : x;
    char ly = y <= 'Z' ? y + 'a' - 'A' : y;
    if(lx == ly) return x < y;
    return lx > ly;
}

char *P19_3(int cargc, char *cargv){
    char *res = (char *) calloc(cargc, sizeof(char));

    // insertion sort
    for(int i = 0; i < cargc; i++){
        // define location
        int loc;
        for(loc = 0; loc < i; loc++)
            if(compare(cargv[i], res[loc])) break;

        // relocate
        for(int j = i; j > loc; j--) res[j] = res[j-1];

        // insert
        res[loc] = cargv[i];
    }

    return res;
}

char *P19_4(int iargc, int *iargv){
    char *res = calloc(128, sizeof(char));
    int idx = 0;

    bool visit[iargc];
    for(int i = 0; i < iargc; i++) visit[i] = false;
    for(int i = 1; i < iargc; i++){
        if(visit[i]) continue;

        bool dup = false;
        for(int j = 0; j < i; j++){
            if(iargv[i] == iargv[j]){
                dup = true;
                for(int k = i+1; k < iargc; k++)
                    if(iargv[i] == iargv[k])
                        visit[k] = true;
            }
        }

        if(dup) idx += sprintf(&res[idx], "%d ", iargv[i]);
    }

    if(idx == 0) idx += sprintf(&res[idx], "-1");
    res[idx] = '\0';
    return res;
}

char *P19_5(char *ptrx, char *ptry){
    char t = *ptrx;
    *ptrx = *ptry;
    *ptry = t;
    return ptrx;
}