#include <stdio.h>
#include <string.h>

#define T 10004
#define ABS(V) (((V) < 0)? -(V): (V))

int main()
{
    char s[T] = {0};
    int t = 0;
    int i = 0;
    int j = 0;
    int o = 0;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        j = strlen(s);
        for (i = 0, j = j - 1; i < j; ++i, --j)
            o += ABS(s[i] - s[j]);

        printf("%d\n", o);
        o = 0;
    }
    
    return 0;
}

