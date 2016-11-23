#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char w1[101];
    char c;
    int i, j, l, s;
    
    gets(w1);
    l = strlen(w1);
    for (i = 0; i < l; i += 2) {
        s = 0;
        for (j = 0; j < (l - 2); j += 2) {
            if (w1[j] > w1[j + 2]) {
                c = w1[j];
                w1[j] = w1[j + 2];
                w1[j + 2] = c;
                s = 1;
            }
        }
        if (s == 0) break;
    }
    
    printf("%s\n", w1);
    return 0;
}
