#include <stdio.h>
#include <string.h>

int main()
{
    int l1, l2, i, d;
    char A[10001] = {0};
    char B[10001] = {0};
    int a[26]     = {0};
    
    scanf("%s", A);
    scanf("%s", B);
    l1 = strlen(A);
    l2 = strlen(B);
    d = 0;
        
    for (i = 0; i < l1; ++i)
        a[A[i] - 'a']++;
        
    for (i = 0; i < l2; ++i)
        a[B[i] - 'a']--;
    
    for (i = 0; i < 26; ++i)
        d += (a[i] < 0)? a[i] * -1: a[i];
    printf("%d\n", d);
    return 0;
}

