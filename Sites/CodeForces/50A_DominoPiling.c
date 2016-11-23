#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int m, n;
    
    scanf("%d %d\n", &m, &n);
    
    /* para flotantes                       */
    /* ((n * m + 1) >> 1) - ((n * m) & 1)); */
    
    printf("%d\n", ((n * m) >> 1));
    return 0;
}
