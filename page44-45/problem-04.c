#include <stdio.h>

int main() {
  double num1, num2, prod;
  printf("Please enter the first number: ");
  scanf("%lf", &num1);
  printf("Please enter the second number: ");
  scanf("%lf", &num2);
  prod = num1*num2;
  printf("The product is: %0.3lf \n", prod);
  return 0;
}
// To compile run: gcc -o <outfile> problem-04.c
