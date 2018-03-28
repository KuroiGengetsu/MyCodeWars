#include <stdio.h>

#define TEST 25

int solution(int number);

int main() {
  for (int i = 0; i < TEST; i++)
    printf("i : %d, solution: %d\n", i, solution(i));
  //  printf("solution(%d) = %d\n", TEST, solution(TEST));
  return 0;
}

int solution(int number) {
  int tmp, sum = 0;
  for (int n3 = 1; n3 <= number / 3; n3++) {
    if ((tmp = n3 * 3) >= number)
      break;
    else if (n3 % 5 == 0)
      continue;
    sum += tmp;
  }
  for (int n5 = 1; n5 <= number / 5; n5++) {
    if ((tmp = n5 * 5) >= number)
      break;
    sum += tmp;
  }
  return sum;
}

int solution2(int number) {
  int sum = 0;
  for (int i = 0; i < number; i++)
    if ((i % 3) == 0 || (i % 5) == 0)
      sum += i;
  return sum;
}

