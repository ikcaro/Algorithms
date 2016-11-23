#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int  n, i, c = 0;
    char w[51];
    
    scanf("%d\n", &n);
    scanf("%s\n", w);
    for (i = 1; i < n; ++i) {
        if (w[i] == w[i - 1])
            ++c;
    }
    printf("%d\n", c);
    return 0;
}
