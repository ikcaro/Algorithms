#include <stdio.h>

#define T 100005

int main()
{
    char s[T];
    int t = 0;
    int d = 0;
    int i = 0;
    
    scanf("%d\n", &t);
    while (t--) {
        scanf("%s", s);
        for (i = 1; s[i] != 0; ++i) {
            if (s[i] == s[i - 1])
                ++d;
        }
        printf("%d\n", d);
        d = 0;
    }

    return 0;
}
