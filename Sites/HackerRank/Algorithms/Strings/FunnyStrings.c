#include <stdio.h>
#include <string.h>

static inline int ABS(int a)
{
    if (a < 0)
        return (a * -1);
    return a;
}

int main()
{
    int t, n, i, j, b;
    char s[10001] = {0};

    scanf("%d\n", &t);
    while(t--) {
        gets(s);
        n = strlen(s);
        b = 1;
        for (i = 1, j = n - 2; i < n && j > 0 && b; ++i, --j) {
            if (ABS(s[i] - s[i - 1]) != ABS(s[j] - s[j + 1]))
                b = 0;
        }
        printf("%s\n", (b)? "Funny": "Not Funny");
    }

    return 0;
}
