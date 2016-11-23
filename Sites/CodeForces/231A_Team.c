#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, t = 0;
    int p[3];
    
    scanf("%d\n", &n);
    while (n--) {
        scanf("%d %d %d\n", &p[0], &p[1], &p[2]);
        t += ((p[0] + p[1] + p[2]) > 1)? 1: 0;
    }
    
    printf("%d\n", t);
    return 0;
}
