#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

#define INF 100000
#define NIL -1

/* BELLMAN-FORD */

typedef struct {
    int u;
    int v;
    int w;
} EDGE;

typedef struct {
    int nv;
    int ne;
    int te;
    EDGE *e;
} GRAPH;

typedef struct {
    int *d;
    int *p;
} SPATH;

void init_graph(GRAPH *g, int nv, int ne)
{
    g->nv = nv;
    g->ne = ne;
    g->te = 0;

    g->e = malloc(sizeof(EDGE) * g->ne);
}

void add_edge(GRAPH *g, EDGE e)
{
    g->e[g->te] = e;
    g->te++;
}

/**
 * for every V initialize distance to inf and predecessor to nil
 * for the vertex src distance to 0
 **/
void initialize(GRAPH *g, SPATH *sp, int s)
{
    int v;

    sp->p = malloc(sizeof(int) * g->nv);
    sp->d = malloc(sizeof(int) * g->nv);

    for (v = 0; v < g->nv; ++v) {
        sp->d[v] = INF;
        sp->p[v] = NIL;
    }
    sp->d[s] = 0;
}


inline void relax(EDGE e, SPATH *sp)
{
    if ((sp->d[e.u] + e.w) < sp->d[e.v]) {
       sp->d[e.v] = sp->d[e.u] + e.w;
       sp->p[e.v] = e.u;
    }
}

void print_sp(GRAPH *g, SPATH *sp)
{
    int v;

    for (v = 0; v < g->nv; ++v)
        printf(" V [%d]: P = %d, D = %d\n", v, sp->p[v], sp->d[v]);
}

/**
 * Input: A graph G whose edges have distinct weights
 * Output:
 **/
int bellman_ford(GRAPH *g, int s)
{
    int v;
    int i;
    SPATH sp;
    EDGE e;

    initialize(g, &sp, s);
    print_sp(g, &sp);

    for (v = 0; v < (g->nv - 1); ++v) {
        for (i = 0; i < g->ne; ++i) {
            printf("V[%d] E[%d]\n", v, i);
            relax(g->e[i], &sp);
            print_sp(g, &sp);
        }
    }

    for (i = 0; i < g->ne; ++i) {
        e = g->e[i];

        if ((sp.d[e.u] + e.w) < sp.d[e.v]) {
            printf("Error:Negative-weight cycle\n");
            return FALSE;
        }
    }

    printf("\nSP\n");
    print_sp(g, &sp);
    return TRUE;
}

int main()
{
    int i;
    int nv;
    int ne;
    int src;
    EDGE e;
    GRAPH g;

    scanf("%d %d\n", &nv, &ne);
    init_graph(&g, nv, ne);
    scanf("%d\n", &src);
    printf("Src %d\n", src);

    for (i = 0; i < ne; ++i) {
        scanf("%d %d %d\n", &e.u, &e.v, &e.w);
        printf("%d] Edge (%d - %d) w(%d)\n", i, e.u, e.v, e.w);
        add_edge(&g, e);
    }

    bellman_ford(&g, src);
    return 0;
}
