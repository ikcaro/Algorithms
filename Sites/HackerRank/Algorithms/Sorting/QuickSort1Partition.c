#include <stdio.h>

#define MAX 1000
int a[MAX];
int L[MAX];
int E[MAX];
int R[MAX];

int main()
{
    int n, i, p, l, e, r, t;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    
    l = e = r = 0;
    p = a[0];
    
    for (i = 0; i < n; ++i) {
        t = p - a[i];
        if (t > 0)
            L[l++] = a[i];
        else if (t < 0)
            R[r++] = a[i];
        else
            E[e++] = a[i];
    }
    for (i = 0; i < l; ++i) printf("%d ", L[i]);
    for (i = 0; i < e; ++i) printf("%d ", E[i]);
    for (i = 0; i < r; ++i) printf("%d ", R[i]);
    return 0;
}

