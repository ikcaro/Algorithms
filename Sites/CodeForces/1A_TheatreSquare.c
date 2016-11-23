#include <stdio.h>

int main(int argc, char *argv[])
{
    long long int n, m, a;
    long long int l;
    
    scanf("%I64d %I64d %I64d\n", &n, &m, &a);
    
    l = ((n / a) + ((n % a) > 0)) * ((m / a) + ((m % a) > 0));
    
    printf("%I64d\n", l);
    return 0;
}
