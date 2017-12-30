#include <stdio.h>

const char* patels[] = {
    "I love you",
    "a little",
    "a lot",
    "passionately",
    "madly",
    "not at all"
};

const char* how_much_i_love_you(int nb_petals) {
    const char* result = patels[(nb_petals-1) % 6];
    return result;
}

int main() {
    puts(how_much_i_love_you(7));
    return 0;
}