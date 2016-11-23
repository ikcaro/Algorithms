#include <stdio.h>

#define MASK 0x00000001

/*
 * 0  0000 0
 * 1  0001 1
 * 2  0010 1
 * 3  0011 2
 * 4  0100 1
 * 5  0101 2
 * 6  0110 2
 * 7  0111 3
 * 8  1000 1
 * 9  1001 2
 * 10 1010 2
 * 11 1011 3
 * 12 1100 2
 * 13 1101 3
 * 14 1110 3
 * 15 1111 4
 * */

int main()
{
    int          i = 0;
    int          b = 0; 
    unsigned int x = 0;
    
    scanf("%lu", &x);
    for (i = 0; i < 32; ++i)
        b += (x & (MASK << i))? 1: 0;

    printf("%d", b);
    return 0;
}
