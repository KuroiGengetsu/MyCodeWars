#include <stdio.h>
#include <inttypes.h>

uint64_t rowSumOddNumbers(uint32_t n)
{
    uint64_t first = (uint64_t)n * n - n + 1;
    uint64_t sum = first;
    for(uint32_t i = 1; i < n; i++) {
        first += 2;
        sum += first;
    }
    return sum;
}
