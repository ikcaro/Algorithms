#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
    int n, v, i, j;
    int a[100];
    int b[100];

    scanf("%d\n", &n);
    memset(a, 0, 100 * sizeof(int));

    for (i = 0; i < n; ++i) {
        scanf("%d", &v);
        a[v]++;
    }

    for (i = 0; i < 100; ++i) {
        for (j = 0; j < a[i]; ++j)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}

