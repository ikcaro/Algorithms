#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t = 0;
    int i = 0;
    int c = 0;
    long n;
    char nc[15];
    
    scanf("%d\n", &t);
    while (t--) {
        scanf("%s", nc);
        n = atol(nc);
        
        for (i = 0; nc[i] != 0; ++i) {
            if (nc[i] != '0' && n % (nc[i] - '0') == 0)
                ++c;
        }
        printf("%d\n", c);
        c = 0;
    }

    return 0;
}

