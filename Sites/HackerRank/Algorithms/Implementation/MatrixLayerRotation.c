#include <stdio.h>
#include <string.h>

unsigned a[300][300];

int main()
{
    unsigned i, j, t[2];
    unsigned m, n, r, d, r1;
    
    scanf("%u %u %u\n", &m, &n, &r);
    for (i = 0; i < m; ++i)
        for(j = 0; j < n; ++j)
            scanf("%u", &a[i][j]);
    
    d = (n > m)? m: n;
    j = 0;
    while (j < (d / 2)) {
        r1 = r % ((2 * (n - (j * 2))) + (2 * ((m- (j * 2)) - 2)));

        while (r1--) {
            t[0] = a[j][j];
            t[1] = a[m - 1 - j][n - 1 - j];

            // rows
            for (i = 1 + j; i < (n - j); ++i) {
                a[j][i - 1] = a[j][i];                         // sup
                a[m - 1 - j][n - i] = a[m - 1 - j][n - i - 1]; // inf
            }
            
            // cols
            for (i = 1 + j; i < (m - j); ++i) {
                a[i - 1][n - 1 - j] = a[i][n - 1 - j];        // izq
                a[m - i][j] = a[m - i - 1][j];                // der
            }

            a[j + 1][j] = t[0];
            a[m - 2 - j][n - 1 - j] = t[1];
        }
        ++j;
    }

    for (i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

