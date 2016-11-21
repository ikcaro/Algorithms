#include <stdio.h>

int main()
{
    unsigned t, n;

    scanf("%u\n", &t);
    while (t--) {
        scanf("%u", &n);
        printf("%u\n", ~n);
    }
    return 0;
}
