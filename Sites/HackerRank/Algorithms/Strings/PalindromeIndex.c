#include <stdio.h>
#include <string.h>

int palindrome(char *s, int n)
{
    int i, j;
    for (i = 0, j = (n - 1); i < j && s[i] == s[j]; ++i, --j);
    return (i >= j);
}

int main()
{
    int n, l, i, j, d;
    char s[100006] = {0};
    
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        d = -1;
        l = strlen(s);
        for (i = 0, j = l - 1; i < j && d == -1; ++i, --j) {
            if (s[i] != s[j])
                d = palindrome(s + i + 1, j - i)? i: j;
        }
        printf("%d\n", d);
    }
    
    return 0;
}

