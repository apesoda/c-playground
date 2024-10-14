#include <stdio.h>

int main(){
  double num1, num2, num3, sum, avg;
  printf("Provide the first number: ");
  scanf("%0.1f", &num1);
  printf("Provide the second number: ");
  scanf("%0.1f", &num2);
  printf("Provide the third number: ");
  scanf("%0.1f", &num3);
  sum = num1 + num2 + num3;
  avg = sum / 3.0;
  printf("The average between %0.1f, %0.1f and %0.1f is %0.1f \n", num1, num2, num3, avg);
  return 0;
}
