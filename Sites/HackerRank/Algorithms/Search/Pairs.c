#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

static int cmp(const void *a, const void *b)
{
    return (*((unsigned*)a) - *((unsigned*)b));
}

int main()
{
    unsigned  n, k, i, j, c;
    unsigned *v;
    
    scanf("%u %u", &n, &k);
    v = (unsigned *)malloc(sizeof(unsigned) * n);
    for (i = 0; i < n; ++i)
        scanf("%u", &v[i]);
    qsort(v, n, sizeof(unsigned), cmp);
    
    c = 0;
    for (i = 0; i < n + 1; ++i)
        for (j = i + 1; j < n && (v[j] - v[i]) <= k; ++j)
            if ((v[j] - v[i]) == k)
                ++c;
    
    printf("%u\n", c);
    return 0;
}

