#include <stdio.h>
#include <string.h>

#define T 1001
int main()
{
    int s[T];
    int n = 0;
    int l = 0;
    int i = 0;
    
    memset(s, 0, T * sizeof(int));
    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &l);
        ++s[l];
    }
        
    for (i = 0; i < T; ++i) {
        if (s[i] != 0) {
            printf("%d\n", n);
            n -= s[i];
        }
    }

    return 0;
}

