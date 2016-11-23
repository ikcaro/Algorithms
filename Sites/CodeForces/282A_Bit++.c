#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n, a = 0;
    char o[4];
    
    scanf("%d\n", &n);
    while (n--) {
        scanf("%s", o);
        a = (o[1] == '+')? a + 1: a - 1;
    }
    
    printf("%d\n", a);
    return 0;
}
