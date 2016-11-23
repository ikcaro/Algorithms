#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, k, kn, s, i, t = 0;
    
    scanf("%d %d\n", &n, &k);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &s);
        
        if (i <= k && s > 0) {
            ++t;
            if (i == k)
                kn = s;
        } else if (kn == s && s > 0) {
                ++t;
        }
    }

    printf("%d", t);
    
    return 0;
}
