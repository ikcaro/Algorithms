#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, k, i, j;
    unsigned m;
    int *v;
    
    scanf("%d", &n);
    scanf("%d", &k);
    
    v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    qsort(v, n, sizeof(int), cmp);
    
    m = 0xFFFFFFFF;
    for (i = 0; i <= (n - k); ++i)
        if (m > v[i + k - 1] - v[i])
            m = v[i + k - 1] - v[i];
    printf("%d\n", m);
    return 0;
}

