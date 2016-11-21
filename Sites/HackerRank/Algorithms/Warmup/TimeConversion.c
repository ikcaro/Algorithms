#include <stdio.h>

int main()
{
    int  h = 0;
    int  m = 0;
    int  s = 0;
    char t;

    scanf("%d:%d:%d%c", &h, &m, &s, &t);
    
    h %= 12;
    if (t == 'P')
        h += 12;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}
