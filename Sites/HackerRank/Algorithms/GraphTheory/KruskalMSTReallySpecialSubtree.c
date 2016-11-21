#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    int u;
    int v;
    int w;
} VLIST;

typedef struct {
    int n;
    int m;
    VLIST *V;
} GRAPH;

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

void initg(GRAPH *g, int n, int m)
{
    int i;
    
    g->n = n;
    g->m = m;
    g->V = (VLIST *)malloc(g->m * sizeof(VLIST));
}

void freeg(GRAPH *g)
{
    free(g->V);
}

int cmp(const void *a, const void *b)
{
    return ((VLIST *)a)->w - ((VLIST *)b)->w;
}

void KRUSKAL(GRAPH *g, int s)
{
    int i, sum = 0;
    UFIND u;
    
    ufind_init(&u, g->m);
    
    for (i = 1; i <= g->n; ++i)
        make_set(&u, i);
    
    qsort(g->V, g->m, sizeof(VLIST), cmp);
    for (i = 0; i < g->m; ++i) {
        if (find_set(&u, g->V[i].u) != find_set(&u, g->V[i].v)) {
            sum += g->V[i].w;
            union_set(&u, g->V[i].u, g->V[i].v);
        }
    }
    
    printf("%d\n", sum);
}

int main()
{
    int n, m, i, a, b, s, r;
    GRAPH g;

    scanf("%d %d", &n, &m);
    initg(&g, n, m);

    for (i = 0; i < m; ++i)
        scanf("%d %d %d", &g.V[i].u, &g.V[i].v, &g.V[i].w);
    scanf("%d", &s);

    KRUSKAL(&g, s);
    return 0;
}
