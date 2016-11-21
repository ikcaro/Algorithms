#include <stdio.h>
#include <malloc.h>
#define T 10001

int a[T] = {0};
int b[T] = {0};

int main()
{
    int n;
    int m;
    int i;
    int v;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        a[v]++;
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &v);
        b[v]++;
    }

    for (i = 0; i < T; i++) {
        if (a[i] != b[i])
            printf("%d ", i);
    }
    return 0;
}
