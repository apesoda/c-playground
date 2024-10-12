#include <stdio.h>

int main(){
  int num1, num2, quot, remn;
  printf("Enter the dividend: ", num1);
  scanf("%d", &num1);
  printf("Enter the divisor: ", num2);
  scanf("%d", &num2);
  quot = num1/num2;
  remn = num1%num2;
  printf("The quotient is: %d and the remainder is: %d \n", quot, remn);
  return 0;
}
