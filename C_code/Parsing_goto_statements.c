#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define N 2

char *parse(const char *source);
int startswith(const char* source, const char* test);


int main() {
    const char *sources[N] = {
	"1 I am\n"
	"goto 5\n"
	"2 travelling\n"
	"3 down\n"
	"4 the river\n"
	"5 back\n"
	"10 home\n",
	"1 I am\n"
	"goto 5\n"
	"2 travelling\n"
	"3 down\n"
	"4 the river\n"
	"5 back\n"
	"10 home\n"
    };
    /*
    for (int i = 0; i < N-1; i++) {
	char *result = parse(sources[i]);
	assert(strcmp("I am back home", result) == 0);
	free(result);
	}*/
    char *result = parse(sources[0]);
    printf("result is %s\n", result);
    free(result);
    return 0;
}


char *parse(const char *source) {
    char *result = (char*)malloc(sizeof(char) * 100);
    int index = 0;
    const char *p = source;
    while (*p) {
	if (*p == 'g') {
	    const char *start = p+5, *end = start;
	    char next_num[5] = "5";
	    int k = 0;
	    while (*(end) != '\n') {
		next_num[k++] = *end;
		end++;
	    }
	    next_num[k] = '\0';
	    p = end + 1;
	    printf("next_num = %s\n", next_num);
	    while (*p) {
		if (startswith(p, next_num)) {
		    break;
		}
		else {
		    while (*p++ != '\n');
		    continue;
		}
	    }
	}	
	else {
	    while (*p++ != ' ');
	    while (*p != '\n')
		result[index++] = *p++;
	    result[index++] = ' ';
	    p++;
	}
    }
    result[index-1] = '\0';
    return result;
}


int startswith(const char* source, const char* test) {
    int result = 1;
    while (*source != ' ') {
	if (*source != *test) {
	    result = 0;
	    break;
	}
	source++;
	test++;
    }
    return result;
}

