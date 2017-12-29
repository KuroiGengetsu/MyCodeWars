#include <stdio.h>

int bouncingBall(double h, double bounce, double window) {
    if(h <= 0 || bounce <= 0 || bounce >=1 || window >= h)
        return -1;
    int count = 1;
    while((h *= bounce) > window)
        count += 2;
    return count;
}

int main()
{
    int count = bouncingBall(3, 0.66, 1.5);
    printf("count = %d\n", count);
    return 0;
}
