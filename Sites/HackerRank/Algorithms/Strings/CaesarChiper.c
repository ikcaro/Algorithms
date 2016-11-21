#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, k, i;
    char s[101] = {0};
    
    scanf("%d", &n);
    scanf("%s",  s);
    scanf("%d", &k);
    
    for (i = 0; i < n; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = ((((s[i] -'A') + k) % 26)) + 'A';
            
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = ((((s[i] -'a') + k) % 26)) + 'a';
    }
    printf("%s\n", s);
   
    return 0;
}

