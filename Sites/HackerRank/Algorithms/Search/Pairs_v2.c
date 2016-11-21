#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

static int cmp(const void *a, const void *b)
{
    return (*((unsigned*)a) - *((unsigned*)b));
}

int main()
{
    unsigned  n, k, i, c, b;
    unsigned *v;
    
    scanf("%u %u", &n, &k);
    v = (unsigned *)malloc(sizeof(unsigned) * n);
    for (i = 0; i < n; ++i)
        scanf("%u", &v[i]);
    qsort(v, n, sizeof(unsigned), cmp);
    
    c = 0;
    for (i = 0; i < n + 1; ++i) {
        b = v[i] + k;
        if (bsearch(&b, v + i, n - i, sizeof(unsigned), cmp))
            ++c;
    }
    printf("%u\n", c);
    return 0;
}
