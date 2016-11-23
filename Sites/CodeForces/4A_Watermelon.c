#include <stdio.h>

int main(int argc, char *argv[])
{
    int w;

    scanf("%d\n", &w);
    printf("%s\n", (((w % 2) == 0) && (w != 2))? "YES": "NO");
    return 0;
}
