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
    char *V;
} GRAPH;

void initg(GRAPH *g, int n, int m)
{
    int i;
    
    g->n  = n + 1;
    g->m  = m + 1;
    g->D  = (unsigned *)malloc(g->n * sizeof(unsigned));
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
    free(g->V);
    for (i = 1; i < g->n; ++i)
        free(g->M[i]);
    free(g->M);
}

inline int pop_min(GRAPH *g)
{
    int v, imin = 0;
    unsigned vmin = INF;

    for (v = 1; v < g->n; ++v)
        if (g->V[v] == 0 && g->D[v] < vmin)
            vmin = g->D[v], imin = v;

    if (imin > 0)
        g->V[imin] = 1;
    return imin;
}

void DIJKSTRA(GRAPH *g, int s)
{
    int v, u;
    
    memset(g->D, INF, sizeof(unsigned) * g->n);
    memset(g->V, NON, sizeof(char)     * g->n);
    g->D[s] = NON;

    while (1) {
        if (!(u = pop_min(g)))
            break;

        for (v = 1; v < g->n; ++v) {
            if (g->M[u][v] != -1 && ((g->D[u] + g->M[u][v]) < g->D[v]))
                g->D[v] = g->D[u] + g->M[u][v];
        }
    }

    for (v = 1; v < g->n; ++v)
        if (v != s)
            printf("%d ", (g->D[v] != INF)? g->D[v]: -1);
    printf("\n");

}

int main()
{
    int t, n, m, i, a, b, s, r;
    GRAPH g;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        initg(&g, n, m);

        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &r);
            if (g.M[a][b] == -1 || r < g.M[a][b])
                g.M[a][b] = r, g.M[b][a] = r;
        }
        scanf("%d", &s);

        DIJKSTRA(&g, s);
        freeg(&g);
    }
    return 0;
}
