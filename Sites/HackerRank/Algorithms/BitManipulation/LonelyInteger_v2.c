#include <stdio.h>

int main()
{
    int n, v, t = 0;

    scanf("%d\n", &n);
    while (n--) {
        scanf("%d", &v);
        t ^= v;
    }
    printf("%d\n", t);

    return 0;
}
