#include <stdio.h>
#include <string.h>

int L[101][101] = {0};
int P[101][101] = {0};

int lcs(int *X, int *Y, int m, int n)
{
    int i, j;

    for (i = 1; i <= m; ++i) L[i][0] = 0;
    for (j = 0; j <= n; ++j) L[0][j] = 0;
    
    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                P[i][j] = 1;
            } else if (L[i - 1][j] >= L[i][j - 1]) {
                L[i][j] = L[i - 1][j];
                P[i][j] = 2;
            } else {
                L[i][j] = L[i][j - 1];
                P[i][j] = 3;
            }
        }
    }
    return L[m][n];
}

void print_lcs(int *X, int m, int n){
    if (m == 0 || n == 0)
        return;
    
    if(P[m][n] == 1) {
        print_lcs(X, m - 1, n - 1);
        printf("%d ", X[m - 1]);
    } else if(P[m][n] == 3) {
        print_lcs(X, m, n - 1);
    } else {
        print_lcs(X, m - 1, n);
    }
}

int main()
{
    int n, m, i, j;
    int s1[101] = {0};
    int s2[101] = {0};

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; ++i)
        scanf("%d", &s1[i]);
    
    for (i = 0; i < n; ++i)
        scanf("%d", &s2[i]);
    
    lcs(s1, s2, m, n);
    
    print_lcs(s1, m, n);
    return 0;
}
