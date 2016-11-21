#include <stdio.h>

int main()
{
    int n, i, v;
    unsigned char a[101] = {0};

    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &v);
        ++a[v];
    }

    for (i = 0; i <= 101; ++i) {
        if (a[i] == 1) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
