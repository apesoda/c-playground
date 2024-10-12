#include <stdio.h>

int main(){
  int num1, num2, tmp;
  printf("Enter the first number:\n");
  scanf("%d", &num1);
  printf("Enter the second number:\n");
  scanf("%d", &num2);
  tmp = num1;
  num1 = num2;
  num2 = tmp;
  printf("get swapped idiot your first number is now %d and your second number is now %d \n", num1, num2);
  return 0;
}
