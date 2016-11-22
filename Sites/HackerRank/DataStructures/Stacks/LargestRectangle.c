#include <stdio.h>
#include <string.h>

#define T 100004

typedef struct {
    int v[T + 1];
    int t;
} STK;

void init(STK *s)
{
    s->t    = 0;
    s->v[0] = 0;
}

static inline int empty(STK *s)
{
    if (0 == s->t)
        return 1;
    return 0;
}

static inline void push(STK *s, int v)
{
    s->v[++s->t] = v;
}

static inline int top(STK *s)
{
    return s->v[s->t];
}

static inline int pop(STK *s)
{
    return s->v[s->t--];
}

static inline long long max(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    unsigned n, i, h, b;
    long long m = 0;
    int a[T];
    STK s;
    
    scanf("%d\n", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    init(&s);
    a[0] = a[++n] = 0;
    push(&s, 0);
    for (i = 1; i <= n; ++i) {
        while (!empty(&s) && a[i] < a[top(&s)]) {
            h = a[pop(&s)];
            b = (i - top(&s)) - 1;
            m = max(m, h * b);
        }
        push(&s, i);
    }
    printf("%lld\n", m);
    return 0;
}
