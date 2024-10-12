#include <stdio.h>

int main() {
  int num1, num2, sum;
  printf("Please enter the first integer value: \n");
  scanf("%d", &num1);
  printf("Please enter the second integer value: \n");
  scanf("%d", &num2);
  sum = num1 + num2;
  printf("The sum of the integers is: %d \n", sum);
  return 0;
}
// To compile run: gcc -o <outfile> problem-03.c
