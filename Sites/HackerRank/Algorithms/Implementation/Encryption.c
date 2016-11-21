#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char c[10][10];
    char t[82];
    char n, l, r, i, j, k;
    double rs;
    
    scanf("%s", t);
    n = strlen(t);
    rs = sqrt(n);
    l = (int)floor(rs);
    r = (int)ceil(rs);
    if ((l * r) < n)
        l += 1;
    
    k = 0;
    memset(c, 0, 10 * 10);
    for (i = 0; i < l && k < n; ++i) {
        for (j = 0; j < r && k < n; ++j) {
            c[i][j] = t[k++];
        }
    }
    
    for (i = 0; i < r; ++i) {
        for (j = 0; j < l; ++j) {
            if (c[j][i] != 0)
                printf("%c", c[j][i]);
        }
        printf(" ");
    }
    printf("\n");
    
    return 0;
}

