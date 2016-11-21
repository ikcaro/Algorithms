#include <stdio.h>
#include <malloc.h>

#define INF 0xFFFFFFFF
#define NIL 0

typedef struct {
    int n;
    int m;
    int **M;
    unsigned *D;
    int *P;    
} GRAPH;

typedef struct qnode {
    int e;
    struct qnode *next;
    struct qnode *prev;
} QNODE;

typedef struct {
    int n;
    QNODE *q;
    QNODE *f;
} QUEUE;

void initq(QUEUE *q)
{
    q->n = 0;
    q->q = NULL;
    q->f = NULL;
}

int emptyq(QUEUE *q)
{
    return (q->n == 0);
}

void pushq(QUEUE *q, int e)
{
    QNODE *n = NULL;
    
    n = (QNODE *)malloc(sizeof(QNODE));
    n->e = e;
    if (emptyq(q)) {
        q->q = n;
        q->f = n;
        n->next = NULL;
    } else {
        q->q->prev = n;
        n->next = q->q;
        q->q = n;
    }
    n->prev = NULL;
    q->n++;
}

int popq(QUEUE *q) 
{
    int e = q->f->e;
    QNODE *t = NULL;
    
    t = q->f;
    q->f = t->prev;
    free(t);
    q->n--;
    return e;
}

void freeq(QUEUE *q) 
{
    while (!emptyq(q))
        popq(q);
    q->n = 0;
}

void initg(GRAPH *g, int n, int m)
{
    int i;
    
    g->n = n + 1;
    g->m = m + 1;
    g->D = (unsigned *)malloc(g->n * sizeof(unsigned));
    g->P = (int *)malloc(g->n * sizeof(int));
    g->M = (int **)malloc(g->n * sizeof(int *));
    for (i = 0; i < g->n; ++i)
        g->M[i] = (int *)calloc(g->n, sizeof(int));
}

void freeg(GRAPH *g)
{
    int i;
    free(g->D);
    free(g->P);
    for (i = 0; i < g->n; ++i)
        free(g->M[i]);
    free(g->M);
}

void BFS(GRAPH *g, int s)
{
    int i, c;
    QUEUE q;
    
    initq(&q);
    for (i = 1; i < g->n; ++i) {
        g->D[i] = INF;
        g->P[i] = NIL;
    }
    g->D[s] = 0;
    
    pushq(&q, s);
    while (!emptyq(&q)) {
        c = popq(&q);
        for (i = 1; i < g->n; ++i) {
            if (g->M[c][i] == 1 && g->D[i] == INF) {
                g->D[i] = g->D[c] + 6;
                g->P[i] = c;
                pushq(&q, i);
            }
        }
    }
    
    for (i = 1; i < g->n; ++i)
        if (i != s)
            printf("%d ", g->D[i]);
    printf("\n");
    freeq(&q);
}

int main()
{
    int t, n, m, i, a, b, s;
    GRAPH g;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        initg(&g, n, m);
        
        for (i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            g.M[a][b] = 1;
            g.M[b][a] = 1;
        }
        scanf("%d", &s);
        
        BFS(&g, s);
        freeg(&g);
    }
    return 0;
}
