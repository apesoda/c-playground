#include <stdio.h>

int main(){
  int num1, num2, num3;
  float sum, avg;
  printf("Provide the first number: ");
  scanf("%d", &num1);
  printf("Provide the second number: ");
  scanf("%d", &num2);
  printf("Provide the third number: ");
  scanf("%d", &num3);
  sum = num1 + num2 + num3;
  avg = sum / 3.0;
  printf("The average between %d, %d and %d is %0.1f \n", num1, num2, num3, avg);
  return 0;
}
