#include <stdio.h>

unsigned long long fcn(int n) {
    return 1ULL << n;  // 2 的 n 次方
}

unsigned long long fcn2(int n) {
    if(n == 0) return 1;
    if(n == 1) return 2;
    else {
        unsigned long long a = 1, b = 2, c;
        while(--n) {
            c = (6ULL * a) / (5ULL * a - b) * b;
            printf("\nc = %lld\n", c);
            a = b, b = c;
        }
        return c;
    }
}


long long fcn3(long long n) {
    if(n == 0) return 1;
    else if(n == 1) return 2;
    else {
        return (6ULL * fcn(n-2) / (5L * fcn(n-2) - fcn(n-1)) * fcn(n-1));
    }
}

int main () {
    puts("result is:");
    printf("fcn(17) = %llu\n", fcn(17));
    printf("fcn(21) = %llu\n", fcn(21));
    printf("fcn(14) = %llu\n", fcn(14));
    printf("fcn(33) = %llu\n", fcn(33));
    return 0;
}
