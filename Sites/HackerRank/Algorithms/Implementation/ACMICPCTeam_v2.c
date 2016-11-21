#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *s;
    int   l;
} TOP;

inline static int OR(TOP *a, TOP *b)
{
    int i, c;
    for (i = 0, c = 0; i < a->l; ++i)
        if ((a->s[i] - '0') | (b->s[i] - '0'))
            ++c;
    return c;
}

int main()
{
    TOP *t;
    int n, m, i, j, c;
    int mt = 0, mp = 0;

    scanf("%d %d", &n , &m);
    t = (TOP *)malloc(sizeof(TOP) * n);
    for (i = 0; i < n; ++i) {
        t[i].s = (char *)malloc(m * sizeof(char) + 1);
        t[i].l  = m;
        scanf("%s", t[i].s);
    }

    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
            if (i != j) {
                c = OR(&t[i], &t[j]);
                if (mt < c) {
                    mt = c;
                    mp = 1;
                } else if (c == mt) {
                    mp++;
                }
            }
        }
    }

    printf("%d\n", mt);
    printf("%d\n", mp);
    return 0;
}
