#include <stdio.h>
#include <string.h>

#define AS 1002

void isort(int *a, int n)
{
    int i, j, t, s = 0;
    
    for (i = 1; i < n; ++i) {
        t = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            --j;
            ++s;
        }
        a[j + 1] = t;
    }
    printf("%d\n", s);
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
