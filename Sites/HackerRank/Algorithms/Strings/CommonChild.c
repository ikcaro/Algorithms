#include <stdio.h>
#include <string.h>

int L[5001][5001] = {0};


inline int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs(char *X, char *Y, int m, int n)
{
   int i, j;

   for (i = 0; i <= m; ++i) {
     for (j = 0; j <= n; ++j) {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i - 1] == Y[j - 1])
         L[i][j] = L[i - 1][j - 1] + 1;
       else
         L[i][j] = max(L[i - 1][j], L[i][j - 1]);
     }
   }
   return L[m][n];
}

int main()
{
    int l1, l2;
    char s1[5001] = {0};
    char s2[5001] = {0};

    scanf("%s", s1);
    scanf("%s", s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    printf("%d\n", lcs(s1, s2, l1, l2));
    
    return 0;
}

