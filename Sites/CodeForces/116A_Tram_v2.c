#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, a, b, c, m;
    c = m = 0;
    
    scanf("%d\n", &n);
    while (n--) {
        scanf("%d %d\n", &a, &b);
        c += b - a;
        if (c > m)
            m = c;
    }
    
    printf("%d\n", m);
    return 0;
}
