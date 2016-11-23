#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char w[101];
    int  i;
    
    gets(w);
    for (i = 0; w[i] != 0; ++i) {
        if (w[i] == 'H' || w[i] == 'Q' || w[i] == '9')
            break;
    }
    printf("%s\n", (w[i] == 0)? "NO": "YES");
    return 0;
}
