#include <string.h>
#include <stdio.h>
#include <malloc.h>
  
int index(int *A, int l, int r, int key)
{
    int m;
    while ((r - l) > 1) {
        m = l + (r - l) / 2;
        if (A[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}
 
int LIS(int *A, int n)
{
    int len, i; 
    int *L = (int *)malloc(n * sizeof(int));
    
    memset(L, 0, sizeof(int) * n);
    L[0] = A[0];
    len  = 1;
    for (i = 1; i < n; ++i) {
        if (A[i] < L[0])
            L[0] = A[i];
        else if (A[i] > L[len - 1])
            L[len++] = A[i];
        else
            L[index(L, -1, len - 1, A[i])] = A[i];
    }
    return len;
}
 
int main()
{
    int n, i;
    int *A;
    
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    printf("%d\n", LIS(A, n));
    return 0;
}
