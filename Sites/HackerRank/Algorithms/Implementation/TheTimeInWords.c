#include <stdio.h>
#include <string.h>

#define HALF    30
#define QUARTER 15

char D[][10] = {
    {"o' clock"},
    {"one"},        /* 1 */
    {"two"},        /* 2 */
    {"three"},      /* 3 */
    {"four"},       /* 4 */
    {"five"},       /* 5 */
    {"six"},        /* 6 */
    {"seven"},      /* 7 */
    {"eight"},      /* 8 */
    {"nine"},       /* 9 */
    {"ten"},        /* 10 */
    {"eleven"},     /* 11 */
    {"twelve"},     /* 12 */
    {"thirteen"},   /* 13 */
    {"fourteen"},   /* 14 */
    {"quarter"},    /* 15 */
    {"sixteen"},    /* 16 */
    {"seventeen"},  /* 17 */
    {"eighteen"},   /* 18 */
    {"nineteen"},   /* 19 */
    {"twenty"},     /* 20 */
    {"half"},       /* 30 21 */
};

char M[2][10]  = {"minute", "minutes"};
char PT[2][10] = {"past"  , "to"};

int main()
{
    int h, m;
    int mm[2];
    
    scanf("%d\n", &h);
    scanf("%d\n", &m);

    if (m == 0) {
        printf("%s %s\n", D[h], D[m]);
        return 0;
    }

    if (m == HALF) {
        printf("%s %s %s\n", D[m - 9], PT[0], D[h]);
        return 0;
    }
    
    if (m == QUARTER) {
        printf("%s %s %s\n", D[m], PT[0], D[h]);
        return 0;
    }

    if ((60 - m) == QUARTER) {
        m = 60 - m;
        h += 1;
        h %= 12;
        printf("%s %s %s\n", D[m], PT[1], D[h]);
        return 0;
    }

    if (m < HALF) {
        if (m <= 20) {
            printf("%s %s %s %s\n", D[m], M[m > 1], PT[0], D[h]);
        } else {
            mm[0] = (m / 10) * 10;
            mm[1] = m % 10;
            printf("%s %s %s %s %s\n", D[mm[0]], D[mm[1]], M[1], PT[0], D[h]);
        }
        return 0;
    }
    
    if (m > HALF) {
        m = 60 - m;
        h += 1;
        h %= 12;

        if (m <= 20) {
            printf("%s %s %s %s\n", D[m], M[m > 1], PT[1], D[h]);
        } else {
            mm[0] = (m / 10) * 10;
            mm[1] = m % 10;
            printf("%s %s %s %s %s\n", D[mm[0]], D[mm[1]], M[1], PT[1], D[h]);
        }
        return 0;
    }

    return 0;
}

