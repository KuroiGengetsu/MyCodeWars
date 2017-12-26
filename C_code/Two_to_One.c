#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *longest(char *s1, char* s2) {
    char *ss1 = s1, *ss2 = s2;
    _Bool alpha[26] = {0};
    while(*ss1 != '\0')
    {
        if(!alpha[*ss1 - 'a'])
            alpha[*ss1 - 'a'] = 1;
        ss1++;
    }
    while(*ss2 != '\0')
    {
        if(!alpha[*ss2 - 'a'])
            alpha[*ss2 - 'a'] = 1;
        ss2++;
    }
    char result[27], k = 0;
    for(int i = 0; i < 26; i++)
        if(alpha[i])
            result[k++] = 'a' + i;
    result[k] = '\0';
    char *r = malloc(sizeof(char) * (k+1));
    strcpy(r, result);
    return r;
}

int main()
{
    char *s = longest("xyaabbbccccdefww", "xxxxyyyyabklmopq");
    while(*s != '\0')
        putchar(*s++);
    putchar('\n');
    return 0;
}
