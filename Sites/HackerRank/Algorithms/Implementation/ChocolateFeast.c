#include <stdio.h>

int main()
{
    int t, n, c, m;
    int tc, tw, tb;
    
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d %d %d\n", &n, &c , &m);
        
        tc = n / c;
        tw = tc;
        tb = tc;
        while (tc > 0) {
            tc = tw / m;
            tw = tw % m + tc;
            tb += tc;
        }
        printf("%d\n", tb);
    }
    
    return 0;
}

