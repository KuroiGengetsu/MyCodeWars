#include <stdio.h>

long long powll(long long n, int x) {
    long long sum = 1;
    while(x--)
        sum *= n;
    return sum;
}

long long findNb(long long m) {
    long long sum = 0;
    long long n = 1;
    while(sum < m) {
        sum += powll(n++, 3);
    }
    if(sum == m)
        return n-1;
    else
        return -1;
}

int main() {
    long long n = findNb(135440716410000);
    printf("n = %Ld\n", n);
    return 0;
}
