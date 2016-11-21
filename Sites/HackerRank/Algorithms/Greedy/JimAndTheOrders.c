#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i;
    int v;
} ARR;

static int cmp(const void *a, const void *b)
{
    ARR a1 = *((ARR *)a);
    ARR b1 = *((ARR *)b);

    if (a1.v < b1.v)
        return -1;
    else if (a1.v > b1.v)
        return 1;
    else if (a1.i < b1.i)
        return -1;
    return 0;
}

int main()
{
    int n;
    int t;
    int d;
    int i;
    ARR a[1000];

    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d %d\n", &t, &d);
        a[i].i = i + 1;
        a[i].v = t + d;
    }

    qsort(a, n, sizeof(ARR), cmp);
    for (i = 0; i < n; ++i)
        printf("%d ", a[i].i);
    printf("\n");

    return 0;
}
