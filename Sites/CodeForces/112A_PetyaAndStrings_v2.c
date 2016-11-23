#include <stdio.h>

int main(int argc, char *argv[])
{
    char w1[101], w2[101];
    
    gets(w1);
    gets(w2);
    printf("%d\n", strcasecmp(w1, w2));
    return 0;
}
