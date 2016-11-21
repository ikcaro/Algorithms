#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int get_dmedian(int *e, int d)
{
    int dm = 0;
    int m = d / 2;
    int i = 0;
    int c = 0;
    
    if ((d % 2) == 0) {
        for (i = 0; i < 201; ++i) {
            c += e[i];
            if (c == m) {
                dm = i;
                for (i = i + 1;e[i] == 0; ++i);
                dm += i;
                break;
            } else if (c > m) {
                dm = 2 * i;
                break;
            }
        }
    } else {
        m += 1;
        for (i = 0; i < 201; ++i) {
            c += e[i];
            if (c >= m) {
                dm = 2 * i;
                break;
            }
        }
    }
    
    return dm;
}

int main()
{
    int  expenditures[201];
    int  notifications = 0;
    int *arr;
    int  n, d, i, dm;
    
    memset(expenditures, 0, sizeof(int) * 201);
    scanf("%d %d", &n, &d);
    arr = malloc(n * sizeof(int));
    
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        
        if (i >= d) {
            dm = get_dmedian(expenditures, d);
            if (arr[i] >= dm)
                ++notifications;
            
            --expenditures[arr[i - d]];
        }
        ++expenditures[arr[i]];
    }
    printf("%d\n", notifications);
    return 0;
}
