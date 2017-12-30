#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int64_t foldTo(double distance) {
    if(distance <= 0)
        return -1;
    int64_t n = 0;
    double thin = 0.0001;
    double thick = thin;
    while(thick < distance) {
        thick = pow(2, n+1) * thin;
        n++;
    }
    return n;
}

int main() {
    if(foldTo(0.00023) == 2)
        puts("steaf");
    return 0;
}

