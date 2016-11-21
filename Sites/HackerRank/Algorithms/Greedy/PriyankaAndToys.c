#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

static int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, i, j, c;
    int *v;
    
    scanf("%d", &n);
    v = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    
    qsort(v, n, sizeof(int), cmp);
    for (i = 0, c = 0; i < n; ) {
        for (j = i; j < n && v[j] <= (v[i] + 4); ++j);
        i = j;
        ++c;
    }
    printf("%d\n", c);
    return 0;
}

