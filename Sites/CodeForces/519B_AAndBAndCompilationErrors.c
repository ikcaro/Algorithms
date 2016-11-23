#include <stdio.h>

int main()
{
    unsigned n, m, v, t = 0, tt = 0;

    scanf("%u\n", &n);
    m = n;
    while (m--) {
        scanf("%u", &v);
        t ^= v;
    }

    m = n - 1;
    while (m--) {
        scanf("%u", &v);
        t ^= v;
        tt ^= v;
    }
    printf("%u\n", t);

    m = n - 2;
    while (m--) {
        scanf("%u", &v);
        tt ^= v;
    }
    printf("%u\n", tt);

    return 0;
}
