// BOJ 1152 [Word Count]
// Supported by GitHub Copilot

#include <cstdio>
int main() {
    char c=' '; int n=0, s=0, e=1;
    while (c != '\n') {
        if(c == ' '){
            if(s) n++, e++;
        }
        else s=1, e=0;
        scanf("%c", &c);
    }
    printf("%d", ++n-e);
}
