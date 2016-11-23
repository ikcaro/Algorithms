#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n, l;
    char w[101] = {0};
    
    scanf("%d\n", &n);
    while (n--) {
        scanf("%s\n", w);
        l = strlen(w);
        if (l <= 10) {
            printf("%s\n", w);
        } else {
            printf("%c%d%c\n", w[0], (l - 2), w[l - 1]);
        }
    }
    
    return 0;
}
