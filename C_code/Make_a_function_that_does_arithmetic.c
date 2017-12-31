#include <stdio.h>
#include <string.h>

double arithmetic(double a, double b, char* operator) {
    if(strcmp(operator, "add") == 0)
        return (a+b);
    else if(strcmp(operator, "subtract") == 0)
        return (a-b);
    else if(strcmp(operator, "multiply") == 0)
        return a*b;
    else if(strcmp(operator, "divide") == 0)
        return a/b;
}

double arithmetic2(double a, double b, char* operator) {
    switch(*operator) {
        case 'a':
            return a+b;
        case 's':
            return a-b;
        case 'm':
            return a*b;
        case 'd':
            return a/b;
    }
}
