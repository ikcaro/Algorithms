#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, s;
    int v[5] = {0, 0, 0, 0, 0};
    
    scanf("%d\n", &n);
    while (n--) {
        scanf("%d", &s);
        ++v[s];
    }
    
    v[0] += v[4];
    
    v[0] += v[3];
    v[1]  = (v[1] > v[3])? (v[1] - v[3]): 0;
    
    v[0] += v[2] / 2;
    v[2]  = v[2] % 2;
    
    v[0] += v[2];
    v[1] -= (v[2] > 0)? 2: 0;
    v[0] += (v[1] / 4) + (((v[1] % 4 ) > 0)? 1: 0);
    
    printf("%d\n", v[0]);
    return 0;
}
