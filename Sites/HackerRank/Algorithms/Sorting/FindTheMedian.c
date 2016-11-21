#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

static int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, i;
    int *v;
    
    scanf("%d", &n);
    v = malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    qsort(v, n, sizeof(int), cmp);
    printf("%d\n", v[n / 2]);
    return 0;
}

