#include <stdio.h>
#include <string.h>

#define T 100005
int main()
{
    char s[T];
    char a[27];
    int t = 0;
    int i = 0;
    
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, 27);
        
        scanf("%s", s);
        for (i = 0; s[i] != 0; ++i)
            a[s[i] - 'a'] = 1;

        scanf("%s", s);
        for (i = 0; s[i] != 0; ++i)
            if (a[s[i] - 'a'] == 1)
                break;

        printf("%s\n", (s[i] != 0)? "YES": "NO");
    }
    
    return 0;
}

