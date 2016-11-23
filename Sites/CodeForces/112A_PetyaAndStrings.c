#include <stdio.h>

int main(int argc, char *argv[])
{
    char w1[101], w2[101], c[2];
    int  i, r;
    
    gets(w1);
    gets(w2);
    for (i = 0; w1[i] != 0; ++i) {
        c[0] = (char)tolower(w1[i]);
        c[1] = (char)tolower(w2[i]);
        
        r = c[0] - c[1];
        r = (r > 0)? 1: (r < 0)? -1: 0;
        if (r != 0) break;
    }
    
    printf("%d\n", r);
    return 0;
}
