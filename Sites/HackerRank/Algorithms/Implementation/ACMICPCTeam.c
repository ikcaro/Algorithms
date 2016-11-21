#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

unsigned char bset[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 
    2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 
    2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 
    4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 
    2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 
    3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 
    4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 
    3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 
    4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 
    3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 
    5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 
    4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 
    2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 
    3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 
    4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 
    4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 
    4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 
    6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 
    3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 
    4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 
    5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 
    5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 
    6, 7, 6, 7, 7, 8
};

typedef struct {
    unsigned long long t[8];
    int c;
    int l;
} TOP;

inline static int cones(unsigned long long x)
{
    return bset[ x        & 0xFF] + bset[(x >>  8) & 0xFF]
         + bset[(x >> 16) & 0xFF] + bset[(x >> 24) & 0xFF]
         + bset[(x >> 32) & 0xFF] + bset[(x >> 40) & 0xFF]
         + bset[(x >> 48) & 0xFF] + bset[(x >> 56) & 0xFF];
}

inline static void strtobin(TOP *t, char *s, int n)
{
    static int i, j;
    
    memset(t, 0, sizeof(TOP));
    for (i = 0, j = 0; s[i] != 0; ++i) {
        t->c    += s[i] - '0';
        j = ((i % 64) == 0 && i != 0)? j + 1: j;
        t->t[j]  = (t->t[j] << 1) | (unsigned long long)(s[i] - '0');
    }
    t->l = j + 1;
}

inline static int OR(TOP *a, TOP *b)
{
    int i, c = 0;
    for (i = 0; i < a->l; ++i)
        c += cones(a->t[i] | b->t[i]);
    return c;
}

int main()
{
    TOP *t;
    char s[501];
    int n, m, i, j, c;
    int mt = 0, mp = 0;
    
    scanf("%d %d", &n , &m);
    
    t = (TOP *)malloc(sizeof(TOP) * n);
    for (i = 0; i < n; ++i) {
        scanf("%s", s);
        strtobin(&t[i], s, m);
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
