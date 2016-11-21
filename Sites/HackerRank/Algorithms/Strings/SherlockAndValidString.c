#include <stdio.h>
#include <string.h>

int main()
{
    int l, i, j, d, p;
    char A[100001] = {0};
    int a[26]      = {0};
    int b[26]      = {0};
    
    scanf("%s", A);
    l = strlen(A);
        
    for (i = 0; i < l; ++i)
        a[A[i] - 'a']++;
    
    for (i = 0; i < 26; ++i) {
        d = 0;
        for (j = 0; j < 26; ++j)
            if (i != j & a[i] > 0 && a[j] > 0 && a[i] != a[j])
                d++;
        b[i] = d;
    }
    for (i = 0, d = 0; i < 26; ++i) 
        if (b[i] > 1)
            d++;
        
    printf("%s\n", (d <= 1)? "YES": "NO");
    return 0;
}

