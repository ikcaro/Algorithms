#include <stdio.h>

#define MASK 0x00000001
/*
 * 7 3 1
 * 8    0001000
 * 5    0000110
 * 111  1101111
 * 17   0010001
 *      = 0 
 * 
 * 3 3 3
 * 1    001
 * 2    010
 * 3    011
 * 4    100
 *      = 3
 * 
 * */


int main()
{
    int i = 0;
    int j = 0;
    int n = 0;
    int m = 0; 
    int k = 0;
    int d = 0;
    int f = 0;
    int x[1000];
    
    scanf("%d %d %d", &n, &m, &k);
    for (i = 0; i <= m; ++i)
        scanf("%d\n", &x[i]);
        
    for (i = 0; i < m; ++i) {
        d = 0;
        for (j = 0; j < n; ++j) {
            d += (((x[m] >> j) & MASK) != ((x[i] >> j) & MASK));
            if (d > k) break;
        }
        f += (d <= k); 
    }
    
    printf("%d", f);
    return 0;
}
