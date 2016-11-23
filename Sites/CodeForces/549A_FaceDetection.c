#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, m, fs = 0;
    int i, j, ii, jj, k;
    char p[51][51] = {0};
    char f[4] = {'f', 'a', 'c', 'e'};
    char v[4] = {0x01, 0x02, 0x04, 0x08};
    char e = 0;
    
    scanf("%d %d\n", &n, &m);
    for (i = 0; i < n; ++i)
        scanf("%s", &p[i]);
    
    for (i = 0; i < (n - 1) && n != 1; ++i) {
        for (j = 0; j < (m - 1) && m != 1; ++j) {
            for (k = 0; k < 4; ++k) {
                for (ii = i; ii < (i + 2); ++ii) {
                    for (jj = j; jj < (j + 2); ++jj) {
                        e |= (f[k] == p[ii][jj])? v[k]: 0x00;
                    }
                }
            }
            if (e == 0x0f)
                ++fs;
            e = 0x00;
        }
    }
    
    printf("%d\n", fs);
    return 0;
}
