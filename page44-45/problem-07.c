#include <math.h>
#include <stdio.h>

int main(){
  float base, exp;
  printf("Enter the base number: ");
  scanf("%f", &base);
  printf("Enter the exponent: ");
  scanf("%f", &exp);

  printf("%0.1f to the power of %0.1f is: %0.2f\n", base, exp, pow(base, exp));
  return 0;
}
