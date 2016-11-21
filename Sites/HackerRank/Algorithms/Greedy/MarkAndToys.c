#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
    return *((unsigned *)a) - *((unsigned *)b);
}

int main()
{
    unsigned  i;
    unsigned  n;
    unsigned  k;
    unsigned *p = NULL;

    scanf("%u %u\n", &n, &k);
    p = malloc(n * sizeof(unsigned));

    for (i = 0; i < n; ++i)
        scanf("%u", &p[i]);
    qsort(p, n, sizeof(unsigned), cmp);

    for (i = 0; p[i] < k; ++i)
        k = k - p[i];
    printf("%d\n", i);

    return 0;
}
