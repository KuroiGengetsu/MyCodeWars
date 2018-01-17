#include <stdio.h>
#include <stdlib.h>  // strtol
#include <string.h>  // strlen
#include <ctype.h>

/**
 * 十六进制转十进制
 */

int hex2dec(const char *src);
int hex_to_dec(const char *source);

/**
 * 任意进制转十进制
 */

int radix2dec(const char *src, int base);
int radix_to_dec(const char *source, int base);

int main() {
    printf("%d\n", hex2dec("AE"));
    printf("%d\n", hex_to_dec("AE"));
    printf("%d\n", radix2dec("AE", 16));
    printf("%d\n", radix_to_dec("AE", 16));
    printf("%d\n", radix_to_dec("11111111", 2));
    return 0;
}

int hex2dec(const char *src) {
    int bit, len, result;
    bit = 1;
    len = strlen(src);
    result = 0;
    for(int i = len-1; i >= 0; i--) {
        if(isdigit(src[i]))
            result += (src[i] - '0') * bit;
        else if(isupper(src[i]))
            result += (src[i] - 'A' + 10) * bit;
        else
            result += (src[i] - 'a' + 10) * bit;
        bit *= 16;
    }
    return result;
}

int hex_to_dec(const char *source) {
    return (int)strtol(source, NULL, 16);
}

int radix2dec(const char *src, int base) {
    int bit, len, result;
    bit = 1;
    len = strlen(src);
    result = 0;
    for(int i = len-1; i >= 0; i--) {
        if(isdigit(src[i]))
            result += (src[i] - '0') * bit;
        else if(isupper(src[i]))
            result += (src[i] - 'A' + 10) * bit;
        else
            result += (src[i] - 'a' + 10) * bit;
        bit *= base;
    }
    return result;
}

int radix_to_dec(const char *source, int base) {
    return (int)strtol(source, NULL, base);
}
