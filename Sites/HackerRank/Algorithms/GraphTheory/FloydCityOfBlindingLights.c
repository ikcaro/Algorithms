#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define INF 9999999

typedef struct {
    int u;
    int v;
    int w;
} EDGE;

typedef struct {
    int n;
    int m;
    EDGE *E;
    unsigned **D;
} GRAPH;

void initg(GRAPH *g, int n, int m)
{
    int i;
    
    g->n = n + 1;
    g->m = m;
    g->E = (EDGE *)malloc(g->m * sizeof(EDGE));
    g->D = (unsigned **)malloc(g->n * sizeof(unsigned *));
    for (i = 1; i < g->n; ++i) {
        g->D[i] = (int *)malloc(g->n * sizeof(unsigned));
        memset(g->D[i], INF, g->n * sizeof(unsigned));
        g->D[i][i] = 0;
    }
}

void freeg(GRAPH *g)
{
    int i;
    
    free(g->E);
    for (i = 1; i < g->n; ++i)
        free(g->D[i]);
    free(g->D);
}

void FLOYD_WARSHALL(GRAPH *g)
{
    int i, j, k;
    unsigned t;
    
    for (i = 0; i < g->m; ++i)
        g->D[g->E[i].u][g->E[i].v] = g->E[i].w;
        
    for (k = 1; k < g->n; ++k)
        for (i = 1; i < g->n; ++i)
            for (j = 1; j < g->n; ++j)
                if (g->D[i][j] > (g->D[i][k] + g->D[k][j])) {
                    t = g->D[i][k] + g->D[k][j]; 
                    g->D[i][j] = (t > INF)? INF: t;
                }
}

int main()
{
    int n, m, i, q, u, v;
    GRAPH g;

    scanf("%d %d", &n, &m);
    initg(&g, n, m);

    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &g.E[i].u, &g.E[i].v, &g.E[i].w);
    }
    FLOYD_WARSHALL(&g);
    
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &u, &v);
        printf("%d\n", (g.D[u][v] < INF)? g.D[u][v]: -1);
    }
    return 0;
}
