#include <stdio.h>

int main()
{
    int n = 0;
    int v = 0;
    int i = 0;
    int c[3] = {0, 0 ,0};

    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &v);
        if (v > 0)
            ++c[0];
        else if (v < 0)
            ++c[1];
        else
            ++c[2];
    }

    printf("%0.6f\n", (double)c[0] / (double)n);
    printf("%0.6f\n", (double)c[1] / (double)n);
    printf("%0.6f\n", (double)c[2] / (double)n);

    return 0;
}
