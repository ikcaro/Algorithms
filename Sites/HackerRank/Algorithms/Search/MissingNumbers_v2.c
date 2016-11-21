#include <stdio.h>
#include <malloc.h>
#define T 10001

int a[T] = {0};

int main()
{
    int n;
    int i;
    int v;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        a[v]++;
    }

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        a[v]--;
    }

    for (i = 0; i < T; i++) {
        if (a[i] != 0)
            printf("%d ", i);
    }
    return 0;
}
