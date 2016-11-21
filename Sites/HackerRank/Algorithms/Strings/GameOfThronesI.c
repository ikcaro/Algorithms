#include <stdio.h>
#include <string.h>

#define AS 26

int main()
{
    int  c[AS];
    char a[100001];
    int  i, im = 0;

    memset(c, 0, sizeof(int) * AS);
    scanf("%s", a);
    
    for (i = 0; a[i] != 0; ++i)
        c[a[i] - 'a']++;

    for (i = 0; i < AS; ++i) {
        if (c[i] != 0 && (c[i] % 2) != 0)
            im++;
    }
    printf("%s\n", (im > 1)? "NO": "YES");

    return 0;
}
