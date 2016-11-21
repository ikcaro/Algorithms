#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n; 
    int k; 
    int q;
    int m;
    int i;
    
    scanf("%d %d %d",&n,&k,&q);
    int *a = malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
       scanf("%d",&a[i]);
    
    k = k % n;
    for(i = 0; i < q; i++){ 
        scanf("%d",&m);
        printf("%d\n", a[(n + m - k) % n]);
    }
    return 0;
}
