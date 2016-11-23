#include <stdio.h>
#define UPPER 0x01
#define LOWER 0x02
#define MIXED 0x03

int main(int argc, char *argv[])
{
    char w[101];
    int  i;
    char c = 0;
    
    scanf("%s\n", w);
    for (i = 1; w[i] != 0; ++i) {
        c |= isupper(w[i])? UPPER: LOWER;
        if (c == MIXED) break;
    }
    
    if (c == UPPER || i == 1) {
        w[0] += (!isupper(w[0]))? -32: 32;
        for (i = 1; w[i] != 0; ++i)
            w[i] += 32;
    }
    
    printf("%s\n", w);
    return 0;
}
