#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    unsigned a, b;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%u %u", &a, &b);
        printf("%u\n", (unsigned)(floor(sqrt(b)) - ceil(sqrt(a))) + 1);
    }
    
    return 0;
}

