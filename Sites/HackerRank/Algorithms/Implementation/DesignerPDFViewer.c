#include <stdio.h>
#include <string.h>

int main()
{
    int i, lts, h = 0;
    int hl[26];
    char word[15];
    
    for (i = 0; i < 26; ++i)
        scanf("%d", &hl[i]);
    
    scanf("%s", word);
    lts = strlen(word);
    for (i = 0; i < lts; ++i)
        if (h < hl[word[i] - 'a'])
            h = hl[word[i] - 'a'];
    
    printf("%d\n", lts * h);
}
