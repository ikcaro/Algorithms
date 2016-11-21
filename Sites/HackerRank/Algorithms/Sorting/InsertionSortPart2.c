#include <stdio.h>
#include <string.h>

#define AS 1000

static inline void p(int *a, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void isort(int *a, int n)
{
    int i, j, t;
    
    for (i = 1; i < n; ++i) {
        t = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = t;
        p(a, n);
    }
}

int main()
{
    int a[AS];
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    isort(a, n);
    return 0;
}
