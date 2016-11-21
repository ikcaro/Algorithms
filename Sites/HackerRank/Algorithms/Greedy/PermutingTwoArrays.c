#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

static int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int t, n, k, i, b;
    int *v1, *v2;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        
        v1 = (int *)malloc(sizeof(int) * n);
        v2 = (int *)malloc(sizeof(int) * n);
        
        for (i = 0; i < n; ++i)
            scanf("%d", &v1[i]);
            
        for (i = 0; i < n; ++i)
            scanf("%d", &v2[i]);
        
        qsort(v1, n, sizeof(int), cmp);
        qsort(v2, n, sizeof(int), cmp);
        
        b = 1;
        for (i = 0; i < n && b; ++i) {
            if ((v1[i] + v2[n - 1 - i]) < k)
                b = 0;
        }
        printf("%s\n", (b)? "YES": "NO");
        
        free(v1);
        free(v2);
    }
    return 0;
}
