#include <stdio.h>
#include <string.h>

int isvow(char c) 
{
    switch (c) {
    case 'A':case 'a':
    case 'E':case 'e':
    case 'I':case 'i':
    case 'O':case 'o':
    case 'U':case 'u':
    case 'Y':case 'y':
        return 1;
    default:
        return 0;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int i, j, l;
    char w1[101] = {0};
    char w2[201] = {0};
    
    scanf("%s\n", w1);
    
    for (i = 0, j = 0; w1[i] != 0; ++i) {
        if (!isvow(w1[i])) {
                w2[j++] = '.';
                w2[j++] = tolower(w1[i]);
        }
    }
    w2[j] = 0;
    printf("%s\n", w2);
    
    return 0;
}
