#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
    int n, v, i;
    int  a[100];
    char b[100];

    scanf("%d\n", &n);
    memset(a, 0, 100 * sizeof(int));

    for (i = 0; i < n; ++i) {
        scanf("%d %s", &v, b);
        a[v]++;
    }

    for (i = 0; i < 100; ++i) {
        if (i != 0)
            a[i] += a[i - 1];

        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

