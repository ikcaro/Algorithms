#include <stdio.h>

/*
 * 1  4    0
 * 2  7    1
 * 3  44   00
 * 4  47   01
 * 5  74   10
 * 6  77   11
 * 7  444  000
 * 8  447  001
 * 9  474  010
 * 10 477  011
 * 11 744  100
 * 12 747  101
 * 13 774  110
 * 14 777  111

 * 2 1 = 2
 * 2 2 = 4
 * 2 3 = 8
 * 2 4 = 16
 * */
 
int two2n(int n)
{
    int r = 1;
    
    if (n == 0)
        return 0;
    
    while (n--)
        r = r * 2;
    return r;
} 

int main()
{
    char n[15];
    int  i = 0;
    unsigned int in = 0;
    int index = 0;
    
    scanf("%s", n);
    for (i = 0; n[i] != 0; ++i)
        in = (in << 1) | ((n[i] == '7')? 0x00000001: 0x00000000);

    while (i--)
        index += two2n(i);
    
    printf("%d", (index + in + 1));    
    return 0;
}
