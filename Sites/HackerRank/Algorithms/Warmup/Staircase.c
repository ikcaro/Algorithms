#include <stdio.h>

int main()
{
    int n = 0;
    int i = 0;
    int j = 0;

    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (j < (n - i - 1))
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }

    return 0;
}
