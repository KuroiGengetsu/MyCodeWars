#include <stdio.h>
#include <stdlib.h>

// other's solution
// #include <stdio.h>
// #include <stdlib.h>

// typedef unsigned long long ull;
// ull perimeter(int n) {
//   ull a = 1, b = 1, t = 1;
//   for (int i = 0; i < n + 2; ++i) {
//     t = a + b; a = b; b = t;
//   }
//   return 4 * (a - 1);
// }

unsigned long long *fib(unsigned long long n);
unsigned long long perimeter(unsigned long long n);
unsigned long long perimeter2(unsigned long long n);

int main() {
    printf("perimeter(5) = %d\n", perimeter(5));
    printf("perimeter(7) = %d\n", perimeter(7));
    return 0;
}


unsigned long long *fib(unsigned long long n) {
    unsigned long long *result, k = 2;
    result = (unsigned long long*)malloc(sizeof(unsigned long long) * n);
    result[0] = 1;
    if(n == 1)
        return result;
    else if(n == 2) {
        result[1] = 1;
        return result;
    }
    else{
        result[1] = 1;
        n -= 2;
        while(n--) {
            result[k] = result[k-1] + result[k-2];
            k++;
        }
        return result;
    }
}


unsigned long long perimeter(unsigned long long n) {
    n += 1;
    unsigned long long *result = fib(n), sum = 0;
    for(int i = 0; i < n; i++) {
        printf("result[%d] = %d\n", i, result[i]);
        sum += result[i];
    }
    free(result);
    return 4 * sum;
}