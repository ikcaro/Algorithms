#include <stdio.h>
#include <ctype.h>

#define T 1003
#define P ((1 << 26) - 1)

int main()
{
    char s[T] = {0};
    unsigned a = 0;
    int i = 0;
    
    fgets(s, T - 1, stdin);
    for (i = 0; s[i] != 0; ++i) {
        s[i] = (char)tolower(s[i]) - 'a';
        if (s[i] >= 0 && s[i] < 26) {
            a |= (1 << s[i]);
        }
    }
    
    printf("%s\n", (P == a)? "pangram": "not pangram");
    return 0;
}
