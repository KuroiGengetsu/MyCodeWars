#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RESULT_LENGTH 4

char *expandedForm(double n);


int main() {
    char * results[RESULT_LENGTH];
    results[0] = expandedForm(1231.24);
    results[1] = expandedForm(7.304);
    results[2] = expandedForm(0.04);
    results[3] = expandedForm(88.353824);
    //    results[4] = expandedForm();
    for (int i = 0; i < RESULT_LENGTH; i++) {
	printf("%s\n", results[i]);
	free(results[i]);
    }
    return 0;
}


char *expandedForm(double n) {
    char * result = (char *)calloc(100, sizeof(char));

    char n_str[50];
    sprintf(n_str, "%f", n);

    int length = strlen(n_str);
    int dot_index = strcspn(n_str, ".");
    char * remove_zero = n_str + length - 1;
    while (*remove_zero == '0') {
	remove_zero--;
	length--;
    }
    *(remove_zero+1) = '\0';

    for (int i = 0; i < length; i++) {
	if (n_str[i] == '0') {
	    if (i != length - 1)
		continue;
	    else
		break;
	}
	int diff = i - dot_index;
	if (diff < 0) {
	    diff *= -1;
	    char * tmp = (char *)calloc(diff, sizeof(char));
	    sprintf(tmp, "%d", (n_str[i] - '0') * (int)pow(10, diff-1));
	    strcat(result, tmp);
	    free(tmp);
	}
	else if (diff > 0) {
	    char * tmp = (char *)calloc(3 + diff, sizeof(char));
	    sprintf(tmp, "%c/%d", n_str[i], (int)pow(10, diff));
	    strcat(result, tmp);
	    free(tmp);
	}
	else if (diff == 0) {
	    continue;
	}
	if (i != length - 1)
	    strcat(result, " + ");
    }
    return result;
}

