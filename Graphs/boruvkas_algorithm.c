#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/* UNION-FIND */

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
    printf("----------------\n");
    for (x = 0; x < u->n; ++x)
        printf("P[%d] V[%d]\n", u->p[x], x);
}

/* BORUVKA's */

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
 * Input: A graph G whose edges have distinct weights
 * Output: a set with the minimum spanning forest of G
 **/
void boruvkas(GRAPH *g)
{
    int i;
    int s1;
    int s2;
    int ntrees = g->nv;

    UFIND uf;
    int *cest;

    ufind_init(&uf, g->nv);
    cest = malloc(sizeof(int) * g->nv);

    /**
     * Create a component i for each vertex (union find)
     *
     * Initialize cheapest vector: it will contain the minimum edge that
     * connects each component to another
     **/
    for (i = 0; i < g->nv; ++i) {
        make_set(&uf, i);
        cest[i] = -1;
    }
    print_sets(&uf);

    printf("MST:\n");
    /**
     * while sub-trees (componentes) > 1
     **/
    while (ntrees > 1) {
        /**
         * for each component search the minimum edge that connects it
         * with other component
         **/
        for (i = 0; i < g->ne; ++i) {
            s1 = find_set(&uf, g->e[i].u);
            s2 = find_set(&uf, g->e[i].v);

            if (s1 != s2) {
                if (cest[s1] == -1 || g->e[cest[s1]].w > g->e[i].w)
                    cest[s1] = i;

                if (cest[s2] == -1 || g->e[cest[s2]].w > g->e[i].w)
                    cest[s2] = i;
            }
        }

        /**
         * add the new components to the MST set
         **/
        for (i = 0; i < g->nv; ++i) {
            if (cest[i] != -1) {
                printf("Trees: %d\n", ntrees);
                s1 = find_set(&uf, g->e[cest[i]].u);
                s2 = find_set(&uf, g->e[cest[i]].v);

                if (s1 != s2) {
                    printf(" Edge (%d - %d) w (%d)\n",
                           g->e[cest[i]].u, g->e[cest[i]].v, g->e[cest[i]].w);
                    union_set(&uf, s1, s2);
                    print_sets(&uf);
                    ntrees--;
                }
            }
        }

        /**
         * clean cheapest vector
         **/
        for (i = 0; i < g->nv; ++i)
            cest[i] = -1;
    }
}

int main()
{
    int nv;
    int ne;
    EDGE e;
    GRAPH g;

    scanf("%d %d\n", &nv, &ne);
    init_graph(&g, nv, ne);

    while (ne--) {
        scanf("%d %d %d\n", &e.u, &e.v, &e.w);
        printf("Edge (%d - %d) w(%d)\n", e.u, e.v, e.w);
        add_edge(&g, e);
    }

    boruvkas(&g);
}
