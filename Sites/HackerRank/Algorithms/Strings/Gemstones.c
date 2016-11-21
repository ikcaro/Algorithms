#include <stdio.h>
#include <string.h>

int main()
{
    unsigned n, i, j, c = 0;
    char r[101] = {0};
    char b[26] = {0};
    int  a[26];
    
    scanf("%d\n", &n);
    memset(a, 0, 26 * sizeof(int));
    
    for (i = 0; i < n; ++i) {
        gets(r);

        memset(b, 0, 26);
        for (j = 0; r[j] != 0; ++j) {
            if (b[r[j] - 'a'] == 0) {
                a[r[j] - 'a'] += 1;
                b[r[j] - 'a']  = 1;
            }
        }
    }

    for (i = 0; i < 26; ++i)
        if (a[i] == n)
            ++c;

    printf("%d\n", c);
    return 0;
}
