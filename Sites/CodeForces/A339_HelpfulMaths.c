#include <stdio.h>
#include <string.h>

static int cmp(const void *p1, const void *p2)
{
    return (*((char *)(p1)) - *((char *)(p2)));
}

int main(int argc, char *argv[])
{
    char w1[101];
    char w2[101];
    int i, j = 0, l;
    
    gets(w1);
    l = strlen(w1);
    qsort(w1, l, sizeof(char), cmp);
    for (i = (l / 2); w1[i] != 0; ++i) {
        w2[j++] = w1[i];
        w2[j++] = '+';
    }
    if (l > 0)
        w2[j - 1] = 0;
    else 
        w2[0] = w1[0];
    
    printf("%s\n", w2);
    return 0;
}
