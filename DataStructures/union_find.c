#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    int *p;
    int *r;
    int n;
} UFIND;

void ufind_init(UFIND *u, int n)
{
    u->n = n;
    u->p = (int *)calloc(n, sizeof(int));
    u->r = (int *)calloc(n, sizeof(int));
}

void ufind_free(UFIND *u)
{
    free(u->p);
    free(u->r);
}

void make_set(UFIND *u, int x)
{
    u->p[x] = x;
    u->r[x] = 0;
}

void link(UFIND *u, int x, int y)
{
    if (u->r[x] > u->r[y]) {
        u->p[y] = x;
    } else {
        u->p[x] = y;
        if (u->r[x] == u->r[y])
            u->r[y] = u->r[y] + 1;
    }
}

int find_set(UFIND *u, int x)
{
    if (x != u->p[x])
        u->p[x] = find_set(u, u->p[x]);
    return u->p[x];
}

void union_set(UFIND *u, int x, int y)
{
    link(u, find_set(u, x), find_set(u, y));
}

void print_sets(UFIND *u)
{
    int x;
    for (x = 1; x < u->n; ++x)
        printf("V[%d] P[%d] R[%d]\n", x, u->p[x], u->r[x]);
}

int main()
{
    int i;
    UFIND u;
    int v = 10;
    int e[5][2] = {
        {1, 6},
        {2, 7},
        {3, 8},
        {4, 9},
        {2, 6}
    };

    ufind_init(&u, v + 1);
    for (i = 1; i <= v; ++i)
        make_set(&u, i);

    /* Connected components */
    for (i = 0; i < (v / 2); ++i) {
        if (find_set(&u, e[i][0]) != find_set(&u, e[i][1]))
            union_set(&u, e[i][0], e[i][1]);
    }
    print_sets(&u);

    ufind_free(&u);
    return 0;
}
