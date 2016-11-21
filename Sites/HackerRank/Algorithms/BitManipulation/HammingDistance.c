#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  s[50003];
char st[50000];
typedef struct {
    char c;
    int p[4];
    char pn;
} CMD;

static inline void cmdC(char *s, int n, CMD *c)
{
    memset(s + c->p[0], c->pn, (c->p[1] - c->p[0] + 1));
}

static inline void cmdH(char *s, int n, CMD *c)
{
    static int   i, h;
    static char *p1, *p2;
    
    h  = 0;
    p1 = s + c->p[0];
    p2 = s + c->p[1];
    for (i = 0; i < c->p[2]; ++i)
        if (p1[i] != p2[i])
            ++h;
    printf("%d\n", h);
}

static inline void cmdS(char *s, int n, CMD *c)
{
    static int s1;
    static int s2;
    static int s3;
    
    s1 = c->p[1] - c->p[0] + 1;
    s2 = c->p[2] - c->p[1] - 1;
    s3 = c->p[3] - c->p[2] + 1;
    
    memmove(st          , s + c->p[2], s3);
    memmove(st + s3     , s + c->p[1] + 1, s2);
    memmove(st + s3 + s2, s + c->p[0], s1);
    memmove(s + c->p[0] , st         , c->p[3] - c->p[0] + 1);
}

static inline void cmdR(char *s, int n, CMD *c)
{
    static int   i, j;
    static int   l;
    static char *p; 
    static char  t;
    
    l = c->p[1] - c->p[0] + 1;
    p =       s + c->p[0];
    for (i = 0, j = (l - 1); i < j; ++i, j--) {
        t    = p[i];
        p[i] = p[j];
        p[j] = t;
    }
}

static inline void cmdW(char *s, int n, CMD *c)
{
    static int i;
    static int j;
    for (i = c->p[0], j = 0; i <= c->p[1]; ++i, ++j)
        st[j] = s[i];
    st[j] = 0;
    printf("%s\n", st);
}

int main()
{
    CMD c;
    int  n, m, i;

    scanf("%d\n", &n);
    gets(s + 1);
    scanf("%d\n", &m);
    for (i = 0; i < m; ++i) {
        scanf("%c ", &c.c);
        switch (c.c) {
        case 'C':
            scanf("%d %d %c\n", &c.p[0], &c.p[1], &c.pn);
            cmdC(s, n, &c);
            break;
        case 'H':
            scanf("%d %d %d\n", &c.p[0], &c.p[1], &c.p[2]);
            cmdH(s, n, &c);
            break;
        case 'S':
            scanf("%d %d %d %d\n", &c.p[0], &c.p[1], &c.p[2], &c.p[3]);
            cmdS(s, n, &c);
            break;
        case 'R':
            scanf("%d %d\n", &c.p[0], &c.p[1]);
            cmdR(s, n, &c);
            break;
        case 'W':
            scanf("%d %d\n", &c.p[0], &c.p[1]);
            cmdW(s, n, &c);
            break;
        }   
    }
   
    return 0;
}
