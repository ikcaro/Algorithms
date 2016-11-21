#include <stdio.h>
#include <malloc.h>

int main()
{
    unsigned int *a, *c, *b;
    int n, m, i, j, f;
    
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
            
        b = malloc(sizeof(unsigned int) * m);
        a = malloc(sizeof(unsigned int) * m);
        c = malloc(sizeof(unsigned int) * m);
        
        for (i = 0; i < m; ++i) {
            scanf("%u", &a[i]);
            b[i] = c[i] = 0;
        }
        
        b[0] = a[0];
        c[m - 1] = a[m - 1];
        f = 0;
        
        for (i = 1, j = (m - 2); i < m; ++i, --j) {
            b[i] = b[i - 1] + a[i];
            c[j] = c[j + 1] + a[j];
        }
        
        for (i = 1; i < (m - 1) && f == 0; ++i)
            if (b[i - 1] == c[i + 1])
                f = 1;
        if (m == 1)
            f = 1;
        printf("%s\n", (f)? "YES": "NO");
        
        free(a);
        free(b);
        free(c);
    }
    
    return 0;
}

