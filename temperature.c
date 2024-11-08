#include <stdio.h>

int main() {
  int opt;
  float cel, fah;
  printf("## CONVERT YOUR TEMPS ##\n(1) C->F\n(2) F->C\nConvert from Celsius to Fahrenheit?(1) Or from Fahrenheit to Celsius?(2): ");
  scanf("%d", &opt);
  if (opt == 1) {
    printf("Enter your temperature in C: ");
    scanf("%f", &cel);
    fah = cel * (9.0/5.0) + 32;
    printf("%0.1f degrees Celsius is %0.1f degrees Fahrenheit \n", cel, fah);
  }
  else if (opt == 2) {
    printf("option 2");
  }
  else {
    printf("no\n");
  };
  return 0;
}
