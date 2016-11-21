#include <stdio.h>
#include <string.h>

#define DMK 0xFF00000000000000L
#define DMS 0x8000000000000000LL
#define AS 1000

int isp2(unsigned long long x)
{
    return ((x & (~x + 1)) == x);
}

unsigned long long np2(unsigned long long x)
{
    int  i, j;
    unsigned long long MK = DMK;
    
    for (i = 0; (i < 8) && (x & MK) == 0; ++i, MK >>= 8);
    if (i < 8) {
        x = (x & MK) << (8 * i);
        for (j = 0; (j < 8) && (x & DMS) == 0; ++j, x <<= 1);
        return (DMS >> (j + (8 * i)));
    }

    return 0LL;
}

int main()
{
    int  t;
    char b;
    unsigned long long n;

    scanf("%d", &t);
    while (t--) {
        scanf("%llu", &n);
        b = 0;
        while (n > 1) {
            n = (!isp2(n))? (n - np2(n)): (n / 2);
            b = ~b;
        }
        printf("%s\n", (b == 0)? "Richard": "Louise");
    }
    return 0;
}
