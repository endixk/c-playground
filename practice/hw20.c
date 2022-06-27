#include <stdio.h>
#include <stdlib.h>

void P20_1(int n){
    int i, j;

    // cap
    if(n > 1){
        for(i = 1; i < n; i++) printf(" ");
        printf("*\n");
    }

    // body
    for(i = 0; i < n-2; i++){
        for(j = 2; j < n-i; j++) printf(" ");
        printf("*");
        for(j = 0; j <= 2*i; j++) printf(" ");
        printf("*\n");
    }

    // floor
    for(i = 0; i < 2*n-1; i++) printf("*");
    printf("\n");
}

void P20_2(char *in){
    FILE *fp = fopen(in, "r");

    int p, q;
    while(fscanf(fp, "%d %d", &p, &q) != EOF){
        printf("%d%d", p, q);
    }

    fclose(fp);
    puts("");
}

char *binary(int n){
    char bin[128];
    int i;
    for(i = 0; n > 0; i++){
        bin[i] = '0' + (n % 2);
        n >>= 1;
    }

    char *res = (char *) calloc(i+1, sizeof(char));
    res[i] = '\0';
    for(int x = 0; x < i; x++) res[i-x-1] = bin[x];
    return res;
}

void P20_3(char *in, char *out){
    FILE *fi = fopen(in, "r"),
         *fo = fopen(out, "w");

    int x;
    while(fscanf(fi, "%d", &x) != EOF){
        char *res = binary(x);
        fprintf(fo, "%d = %s\n", x, res);
        free(res);
    }

    fclose(fi);
    fclose(fo);
}