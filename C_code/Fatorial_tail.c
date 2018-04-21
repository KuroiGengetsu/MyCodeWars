#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

typedef struct factor {
    int fac;
    int num;
    struct factor *next;
} factor ;

int zeroes(int base, int number);
factor * get_factor(int num);
int is_prime(int num);
void free_factor(factor *head);
int get_len(factor *head);

int main() {

#if DEBUG
    for (int n = 168; n < 169; n++) {
	factor *head = get_factor(n);
	factor *link = head -> next;
	printf("%d has %d 个 %d", n, link -> num, link -> fac);
	while (link -> next != NULL) {
	    link = link -> next;
	    printf(",  \t%d 个 %d", link -> num, link -> fac);
	}
	printf(".\n");
	free_factor(head);
    }
#endif

    printf("%d has %d zeroes.\n", 9614, zeroes(168, 9614));
    /* printf("%d has %d zeroes.\n", 7497, zeroes(39, 7497)); */
    return 0;
}

int is_prime(int num) {
    for (int i = 2; i <= num / 2; i++) {
	if (num % i == 0)
	    return 0;
    }
    return 1;
}

factor * get_factor(int num) {
    factor *head = (factor*)malloc(sizeof(factor));
    factor *link = (factor*)malloc(sizeof(factor));
    head -> next = link;
    if (is_prime(num)) {
	link -> fac = num;
	link -> num = 1;
	link -> next = NULL;
	return head;
    }
    link -> num = 0;
    int copy = num;
    for (int i = 2; i <= copy / 2; i++) {
	if (is_prime(i) && num % i == 0) {
	    link -> fac = i;
	    while (num % i == 0) {
		link -> num++;
		num /= i;
	    }
	    if (num == 1)
		break;
	    factor *new = (factor*)malloc(sizeof(factor));
	    link -> next = new;
	    link = new;
	    link -> num = 0;
	}
    }
    link -> next = NULL;
    return head;
}

int zeroes(int base, int number) {
    // 找到 base 的因子, 比如 16 = 2 * 2 * 2 * 2, 10 = 2 * 5, 9 = 3 * 3, 统计从 1 到 number, 有多少个这些因子, 能组成多少个 base 就是 0 的个数
    factor *head = get_factor(base);
    int num_of_facs = get_len(head);
    factor **facs_arr = malloc(sizeof(factor*) * num_of_facs);
    factor *link = head;
    int *sum = (int*)malloc(sizeof(int) * num_of_facs);

    for (int i = 0; i < num_of_facs; i++) {
	facs_arr[i] = link -> next;
	link = link -> next;
    }

    for (int i = 2; i <= number; i++) {
	int tmp = i;
	for (int j = 0; j < num_of_facs; j++) {
	    while (tmp % facs_arr[j] -> fac == 0) {
		tmp /= facs_arr[j] -> fac;
		sum[j]++;
	    }
	}
    }

    int zero = sum[0] / facs_arr[0]-> num;
    for (int i = 1; i < num_of_facs; i++) {
	int times = sum[i] / facs_arr[i] -> num;
	if (times < zero)
	    zero = times;
    }
 
    free(facs_arr);
    free(sum);
    free_factor(head);
    return zero;
}

void free_factor(factor *head) {
    factor *trash = head;
    while (head -> next != NULL) {
	head = head -> next;
	free(trash);
	trash = head;
    }
    free(trash);
}


int get_len(factor *head) {
    int n = 1;
    head  = head -> next;
    while (head -> next != NULL) {
	n++;
	head = head -> next;
    }
    printf("\n");
    return n;
}
