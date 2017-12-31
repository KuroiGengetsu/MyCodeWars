#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// szlst is lstOfArt size, szcat is categories size
char* stockSummary(char** lstOfArt, int szlst, char** categories, int szcat) {
    if(szlst == 0 || szcat == 0)  // if they are empty, return ""
        return "";
    char *result = malloc(sizeof(char) * 11 * (szcat));  // 动态分配空间
    result[0] = '\0';  // 为了使用 strcat
    int sum[szcat];  // 用于计算数字的和
    memset(sum, 0, sizeof(sum));  // 初始化为0
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
    char *result = stockSummary(art, 5, cd, 2);
    puts(result);
    free(result);
    return 0;
}