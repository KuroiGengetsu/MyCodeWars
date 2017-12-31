#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// szlst is lstOfArt size, szcat is categories size
char* stockSummary(char** lstOfArt, int szlst, char** categories, int szcat) {
    if(szlst == 0 || szcat == 0)
        return "";
    char *result = malloc(sizeof(char) * 11 * (szcat));
    result[0] = '\0';
    int sum[szcat];
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < szcat; i++) {
        for(int j = 0; j < szlst; j++) {
            if(categories[i][0] == lstOfArt[j][0]) {
                char *s = lstOfArt[j];
                while(*s < '0' || *s > '9') {
                    if(*s == '\0')
                        break;
                    s++;
                }
                if(*s != '\0')
                    sum[i] += atoi(s);
            }
        }
    }
    for(int i = 0; i < szcat; i++) {
        char tmp[100];
        if(i == szcat-1)
            sprintf(tmp, "(%s : %d)", categories[szcat-1], sum[szcat-1]);
        else
            sprintf(tmp, "(%s : %d) - ", categories[i], sum[i]);
        strcat(result, tmp);
    }
    return result;
}

int main() {
    char *art[5] = {"ABAR ", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    char *cd[2] = {"A", "B"};
    // char *cd[0] = {};
    // "(A : 200) - (B : 1140)"
    puts(stockSummary(art, 5, cd, 2));
    return 0;
}