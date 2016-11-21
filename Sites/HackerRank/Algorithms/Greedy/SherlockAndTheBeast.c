#include <stdio.h>

#define F 0
#define T 1

void print(int *m)
{
    int i;
    
    if (m[T] == 0 && m[F] == 0) {
        printf("-1\n");
    } else {
        for (i = 0; i < m[F]; ++i)
            printf("5");
        for (i = 0; i < m[T]; ++i)
            printf("3");
        printf("\n");
    }
}

int main()
{
    int n, t, i;
    int c[2] = {0, 0};
    int m[2] = {0, 0};
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        c[F] = c[T] = 0;
        m[F] = m[T] = 0;
        
        for (i = 0; i <= n; i += 3) {
            c[F] = i;
            c[T] = n - i;
            if ((c[F] % 3) == 0 && (c[T] % 5) == 0 && c[F] >= m[F]) {
                m[F] = c[F];
                m[T] = c[T];
            }
        }
        print(m);
    }
    
    return 0;
}

