#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, i, m;
    int *a;
    
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    
    qsort(a, n, sizeof(int), cmp);
    
    m = a[1] - a[0];
    for (i = 1; i < n; ++i)
        if ((a[i] - a[i - 1]) < m)
            m = a[i] - a[i - 1];
    
    for (i = 1; i < n; ++i)
        if ((a[i] - a[i - 1]) == m)
            printf("%d %d ", a[i - 1], a[i]);
    printf("\n");
    return 0;
}
