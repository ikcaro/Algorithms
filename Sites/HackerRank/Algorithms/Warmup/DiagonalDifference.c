#include <stdio.h>

int main()
{
    int n = 0;
    int i = 0;
    int j = 0;
    int s = 0;
    int v = 0;

    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &v);
            if (i == j)
                s += v;
            if (j == (n - i - 1))
                s -= v;
        }
    }
    if (s < 0)
        s *= -1;
    printf("%d\n", s);

    return 0;
}
