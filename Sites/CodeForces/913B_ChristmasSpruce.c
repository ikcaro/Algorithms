#include <stdio.h>
#include <string.h>

typedef struct graf_ {
    int p[1001];
    int c[1001];
    int l[1001];
    int s;
} GRAF;

int main()
{
    int n;
    int i;
    int spruce = 1;
    GRAF g;

    memset(&g, 0, sizeof(g));
    scanf("%d", &g.s);
    for (i = 2; i <= g.s; ++i) {
        scanf("%d", &g.p[i]);
        g.c[g.p[i]]++;
    }

    for (i = 1; i <= g.s; ++i) {
        if (g.c[i] == 0)
            g.l[g.p[i]]++;
    }

    for (i = 1; i <= g.s; ++i) {
        if (g.c[i] > 0 && (g.c[i] < 3 || g.l[i] < 3)) {
            spruce = 0;
            break;
        }
    }

    printf("%s\n", (spruce ? "Yes": "No"));
    return 0;
}
