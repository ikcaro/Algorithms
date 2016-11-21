#include <stdio.h>

int main()
{
    char m[100][101];
    int n;
    int i, j;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%s", m[i]);
        
    for (i = 0; i < n; ++i) {
        for (j = 1; j < (n - 1); ++j) {
            if (i > 0 && i < (n - 1))
                if (m[i][j] > m[i - 1][j] && m[i][j] > m[i][j - 1] &&
                    m[i][j] > m[i + 1][j] && m[i][j] > m[i][j + 1])
                    m[i][j] = 'X';
        }
        printf("%s\n", m[i]);
    }
    
    return 0;
}

