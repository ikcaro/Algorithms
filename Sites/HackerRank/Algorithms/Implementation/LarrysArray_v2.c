#include <stdio.h>

#define T 1000

int main()
{
    unsigned t, n, i, j, m;
    int a[T];
    
    scanf("%u\n", &t);
    while (t--) {
        scanf("%d", &n);
        m = 1;
        for (i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            for (j = 0; j < i; ++j)
                m ^= (a[j] > a[i]);
        }
        printf("%s\n", (m)? "YES": "NO");
    }
    return 0;
}


