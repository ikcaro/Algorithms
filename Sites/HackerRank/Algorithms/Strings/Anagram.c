#include <stdio.h>
#include <string.h>

int main()
{
    int n, l, i, l2;
    char s[10001] = {0};
    char a[26];
    int  v;
    
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        l = strlen(s);
        
        v = 0;
        memset(a, 0, 26);
        if ((l % 2) == 0) {
            l2 = l / 2;
            
            for (i = 0; i < l; ++i)
                a[s[i] - 'a'] = (i < l2)? 
                    a[s[i] - 'a'] + 1: 
                    a[s[i] - 'a'] - 1;
            
            for (i = 0; i < 26; ++i)
                if (a[i] > 0)
                    v += a[i];
                
            printf("%d\n", v);
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}

