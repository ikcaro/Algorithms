#include <stdio.h>

int main()
{
    int t = 0;
    int n = 0;
    int h = 1;
    int i = 0;
    
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i)
            h = (i % 2)? h * 2: h + 1;
        printf("%d\n", h);
        h = 1;
    }

    return 0;
}

