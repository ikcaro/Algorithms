#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define INF 0xFFFFFFFF
#define NIL -1
#define NON  0

typedef struct {
    int n;
    int m;
    int **M;
    unsigned *D;
    int  *P;
    char *V;
} GRAPH;

void initg(GRAPH *g, int n, int m)
{
    int i;
    
    g->n  = n + 1;
    g->m  = m + 1;
    g->D  = (unsigned *)malloc(g->n * sizeof(unsigned));
    g->P  = (int  *)malloc(g->n * sizeof(int));
    g->V  = (char *)malloc(g->n * sizeof(char));
    g->M  = (int **)malloc(g->n * sizeof(int *));
    for (i = 1; i < g->n; ++i) {
        g->M[i] = (int *)malloc(g->n * sizeof(int));
        memset(g->M[i], NIL, g->n * sizeof(int));
    }
}

void freeg(GRAPH *g)
{
    int i;
    free(g->D);
    free(g->P);
    free(g->V);
    for (i = 0; i < g->n; ++i)
        free(g->M[i]);
    free(g->M);
}

inline int pop_min(GRAPH *g)
{
    int v, imin = 0;
    unsigned vmin = INF;

    for (v = 1; v < g->n; ++v)
        if (!g->V[v] && g->D[v] < vmin)
            vmin = g->D[v], imin = v;

    if (imin > 0)
        g->V[imin] = 1;
    return imin;
}

void PRIM(GRAPH *g, int s)
{
    int v, u;
    unsigned d = 0;

    memset(g->D, INF, sizeof(unsigned) * g->n);
    memset(g->V, NON, sizeof(char)     * g->n);
    g->D[s] = NON;
    g->P[s] = NIL;

    while (1) {
        if (!(u = pop_min(g)))
            break;

        if (g->P[u] != NIL)
            d += g->M[u][g->P[u]];

        for (v = 1; v < g->n; ++v) {
            if (g->M[u][v] != -1 && (g->M[u][v] < g->D[v])) {
                g->P[v] = u;
                g->D[v] = g->M[u][v];
            }
        }
    }
    
    printf("%u\n", d);
}

int main()
{
    int n, m, i, a, b, s, r;
    GRAPH g;
    
    scanf("%d %d", &n, &m);
    initg(&g, n, m);
    
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &r);
        g.M[a][b] = r;
        g.M[b][a] = r;
    }
    scanf("%d", &s);
    
    PRIM(&g, s);
    freeg(&g);
    return 0;
}
