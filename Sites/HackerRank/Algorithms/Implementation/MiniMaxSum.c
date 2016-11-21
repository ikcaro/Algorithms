#include <stdio.h>

int main()
{
    unsigned sum = 0;
    unsigned min = 0xffffffff;
    unsigned max = 0;
    unsigned a;
    int i = 0;
    
    for (i = 0; i < 5; ++i) {
        scanf("%d", &a);
        sum += a;
        
        if (a < min)
            min = a;
        
        if (a > max)
            max = a;
    }
    
    printf("%u %u\n", (sum - max), (sum - min));
    return 0;
}

