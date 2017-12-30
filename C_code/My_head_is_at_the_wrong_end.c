#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * something wrong with this problem.
 * 
 * 
 */

const char **fix_the_meerkat(const char **arr) {
    const char **result = malloc(sizeof(char*) * 3);
    for(int i = 0; i < 3; i++)
        result[i] = arr[2 - i];
    return result;
}

int main() {
    const char *arr[] = { "tail", "body", "head" };
    const char *expected[] = { "head", "body", "tail"};
    const char **result = fix_the_meerkat(arr);
    printf("sizeof(arr)/sizeof(arr[0]) = %d\n", sizeof(arr)/sizeof(arr[0]));
    if(strcmp(expected[0], result[0]) == 0 && strcmp(expected[1], result[1]) == 0 && strcmp(expected[2], result[2]) == 0) {
        puts("Successfully!");
    }
    return 0;
}
