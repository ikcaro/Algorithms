#include <stdio.h>
#include <malloc.h>

#define A 0
#define C 1
#define T 2
#define G 3

void count(int *c, char v)
{
    switch (v) {
    case 'A': c[A]++;
        break;
    case 'C': c[C]++;
        break;
    case 'T': c[T]++;
        break;
    case 'G': c[G]++;
        break;
    }
}

void decrease(int *c, char v)
{
    switch (v) {
    case 'A': c[A]--;
        break;
    case 'C': c[C]--;
        break;
    case 'T': c[T]--;
        break;
    case 'G': c[G]--;
        break;
    }
}

void diff(int *c, int *r, int l)
{
    int i;
    for (i = A; i <= G; ++i)
        r[i] = (c[i] > l)? c[i] - l: 0;
}

void clean(int *c)
{
    int i;
    for (i = A; i <= G; ++i)
        c[i] = 0;
}

int balanced(int *c, int l)
{
    return (c[A] == l && c[C] == l && c[T] == l && c[G] == l);
}

int valid(int *c, int *r)
{
    return (c[A] >= r[A] && c[C] >= r[C] && 
            c[T] >= r[T] && c[G] >= r[G]);
}

int main()
{
    int   n, i, l, si, sl;
    char *s;
    int   c[4] = {0, 0, 0, 0};
    int   r[4] = {0, 0, 0, 0};
    
    scanf("%d\n", &n);
    s = malloc(n);
    gets(s);
    
    l = n / 4;
    for (i = 0; i < n; ++i)
        count(c, s[i]);
    
    if (balanced(c, l)) {
        printf("0\n");
        return 0;
    }
    
    diff(c, r, l);
    clean(c);
    for (si = 0; si < n; ++si) {
        count(c, s[si]);
        if (valid(c, r))
            break;
    }
    
    sl = si + 1;
    i = 0;
    while (1) {
        while (1) {
            decrease(c, s[i]);
            i++;
            
            if (valid(c, r))
                sl = si - i + 1;
            else
                break;
        }
        si++;
        if (si > n)
            break;
        count(c, s[si]);
    }
    printf("%d\n", sl);

    return 0;
}

