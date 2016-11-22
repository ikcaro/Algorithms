#include <stdio.h>
#include <string.h>

#define T 1000

typedef struct {
    char v[T + 1];
    int t;
} STK;

void init(STK *s)
{
    s->t    = 0;
    s->v[0] = 0;
}

int empty(STK *s)
{
    if (0 == s->t)
        return 1;
    return 0;
}

void push(STK *s, char v)
{
    s->v[++s->t] = v;
}

char top(STK *s)
{
    return s->v[s->t];
}

char pop(STK *s)
{
    return s->v[s->t--];
}

int main()
{
    int n;
    int l;
    int i;
    int b;
    char s[T + 1] = {0};
    STK st;

    scanf("%d\n", &n);
    while (n--) {
        gets(s);
        l = strlen(s);
        b = 0;

        init(&st);
        for (i = 0; i < l && b != 1; ++i) {
            switch (s[i]) {
            case '[':
            case '{':
            case '(':
                push(&st, s[i]);
                break;

            case '}':
                if (top(&st) == '{')
                    pop(&st);
                else
                    b = 1;
                break;

            case ']':
                if (top(&st) == '[')
                    pop(&st);
                else
                    b = 1;
                break;
            case ')':
                if (top(&st) == '(')
                    pop(&st);
                else
                    b = 1;
                break;
            }
        }
        printf("%s\n", (empty(&st) && b == 0)? "YES": "NO");
    }

    return 0;
}
