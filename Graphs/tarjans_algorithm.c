#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define TRUE 1
#define FALSE 0
#define UNDEF -1

typedef struct vert_ {
    int v;
    int index;
    int lowlink;
    int stacking;
} VERT;

typedef struct stack_ {
    int size;
    int top;
    int *v;
} STACK;

typedef struct graph_ {
    int size;
    int lindex;
    char **g;
    VERT *vs;
    STACK s;
} TARJAN;

void init_stack(STACK *s, int size)
{
        s->size = size;
        s->top = -1;
        s->v = (int *)malloc(sizeof(int) * s->size);
}

void push_stack(STACK *s, int v)
{
    if (s->top < s->size)
        s->v[++s->top] = v;
}

int pop_stack(STACK *s)
{
    if (s->top < 0)
        return -1;

    return s->v[s->top--];
}

void init_tarjan(TARJAN *t, int size)
{
    int i;

    t->size = size;

    t->vs = (VERT *)malloc(sizeof(VERT) * t->size);
    for (i = 0; i < t->size; ++i) {
        t->vs[i].v = i;
        t->vs[i].index = UNDEF;
        t->vs[i].lowlink = UNDEF;
        t->vs[i].stacking = FALSE;
    }

    t->g = (char **)malloc(sizeof(char *) * t->size);
    for (i = 0; i < t->size; ++i) {
        t->g[i] = (char *)malloc(sizeof(char) * t->size);
        memset(t->g[i], 0, sizeof(char) * t->size);
    }

    t->lindex = 0;
    init_stack(&t->s, t->size);
}

void strong_connect(TARJAN *t, int v)
{
    int w;

    t->vs[v].index = t->lindex;
    t->vs[v].lowlink = t->lindex;
    t->lindex++;
    push_stack(&t->s, v);
    t->vs[v].stacking = TRUE;

    for (w = 0; w < t->size; ++w) {
        if (t->g[v][w] == 1) {
            if (t->vs[w].index == UNDEF) {
                strong_connect(t, w);
                t->vs[v].lowlink = MIN(t->vs[v].lowlink, t->vs[w].lowlink);
            } else {
                if (t->vs[w].stacking)
                    t->vs[v].lowlink = MIN(t->vs[v].lowlink, t->vs[w].index);
            }
        }
    }

    if (t->vs[v].lowlink == t->vs[v].index) {
        printf("[%d] ", v);
        do {
            w = pop_stack(&t->s);
            t->vs[w].stacking = FALSE;
            printf("%d ", w);
        } while (w != v);
        printf("\n");
    }
}

void tarjan(TARJAN *t)
{
    int i;

    /* DFS for any node that has not been discovered */
    for (i = 0; i < t->size; ++i)
        if (t->vs[i].index == UNDEF)
            strong_connect(t, t->vs[i].v);
}

int main(int argv, char *argc[])
{
    int i, vs, ns;
    int v, w;
    TARJAN t;

    scanf("%d %d\n", &ns, &vs);
    init_tarjan(&t, ns);

    while (vs--) {
        scanf("%d %d\n", &v, &w);
        printf("%d %d\n", v, w);
        t.g[v][w] = 1;
    }

    tarjan(&t);
    return 0;
}
