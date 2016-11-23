#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char w[101];
    scanf("%s\n", w);
    printf("%s\n", (strstr(w, "0000000") || strstr(w, "1111111"))? "YES": "NO");
    return 0;
}

