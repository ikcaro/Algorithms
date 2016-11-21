#include <stdio.h>
#include <string.h>

#define T 1000

int main()
{
    unsigned t, n, i, j, m;
    int a[T];
    
    scanf("%u\n", &t);
    while (t--) {
        scanf("%d", &n);
        m = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            for (j = 0; j < i; ++j)
                m += (a[j] > a[i]);
        }
        printf("%s\n", (m % 2)? "NO": "YES");
    }
    return 0;
}
