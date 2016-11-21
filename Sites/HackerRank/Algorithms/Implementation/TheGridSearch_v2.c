#include <stdio.h>
#include <string.h>

char M[1001][1001];
char m[1001][1001];

int check(int r, int c, int R, int C, int i, int j)
{
    int ii, jj, b = 1;
    if ((i + r) > R || (j + c) > C)
        return 0;
    
    for (ii = 1; ii < r; ++ii) {
        if (memcmp(M[ii + i] + j, m[ii], c) == 0)
            ++b;
        if (b == r)
            return 1;
    }
    return 0;
}

int main()
{
    int  t, i, j, R;
    int  r, C, c, b;
    char *p = NULL;

    scanf("%d\n", &t);
    while (t--) {
        scanf("%d %d\n", &R, &C);
        for (i = 0; i < R; ++i)
            scanf("%s\n", M[i]);

        scanf("%d %d\n", &r, &c);
        for (i = 0; i < r; ++i)
            scanf("%s\n", m[i]);
            
        b = 0;
        for (i = 0; i < R && b != 1; ++i) {
            for (p = (char *)M[i]; (p = strstr(p, m[0])) != NULL; p++) {
                j = p - (char *)M[i];
                if ((b = check(r, c, R, C, i, j)))
                    break;
            }
        }
        printf("%s\n", (b)? "YES": "NO");
    }

    return 0;
}
