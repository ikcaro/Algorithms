#include <stdio.h>

int main(int argc, char *argv[])
{
    char w[101], p = 0;
    int  i, c = 0;
    
    scanf("%s\n", w);
    for (i = 0; w[i] != 0; ++i) {
        c = (w[i] == p)? c + 1: 1;
        if (c == 7) break;
        p = w[i];
    }
    
    printf("%s\n", (c == 7)? "YES": "NO");
    return 0;
}
