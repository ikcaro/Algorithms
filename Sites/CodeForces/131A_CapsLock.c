#include <stdio.h>
#define UPPER 0x01
#define LOWER 0x02
#define MIXED 0x03

int main(int argc, char *argv[])
{
    char w[101];
    int  i;
    char c = 0, c0;
    
    scanf("%s\n", w);
    for (i = 1; w[i] != 0; ++i) {
        c |= isupper(w[i])? UPPER: LOWER;
        if (c == MIXED) break;
    }
    c0 = isupper(w[0])? UPPER: LOWER;
    
    if (i == 1) {
        w[0] += (c0 == UPPER)? 32: -32;
    } else {
        if (c == UPPER) {
            if (c0 == LOWER) {
                w[0] -= 32;
                for (i = 1; w[i] != 0; ++i)
                    w[i] += 32;
            } else {
                for (i = 0; w[i] != 0; ++i)
                    w[i] += 32;
            }
        }
    }
    
    printf("%s\n", w);
    return 0;
}
