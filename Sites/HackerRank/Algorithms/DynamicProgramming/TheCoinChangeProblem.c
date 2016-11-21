#include <stdio.h>

unsigned long long cs[51];
unsigned long long dp[51][251];

unsigned long long cc(unsigned long long *c, int n, int m)
{
    int i, j;

    for (i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (i = 1; i <= m; ++i)
        dp[0][i] = 0;
    
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            if (c[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - c[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    return dp[n][m];
}

int main()
{
    int n, m, i;

    scanf("%d %d\n", &m , &n);
    for (i = 0; i < n; ++i)
        scanf("%llu", &cs[i]);

    printf("%llu\n", cc(cs, n, m));
    return 0;
}
