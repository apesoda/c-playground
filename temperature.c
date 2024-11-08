#include <stdio.h>

int main() {
  int cel, fah, opt;
  printf("## CONVERT YOUR TEMPS ##\n(1) C->F\n(2) F->C\nConvert from Celsius to Fahrenheit?(1) Or from Fahrenheit to Celsius?(2): ");
  scanf("%d", &opt);
  if (opt == 1) {
    printf("Enter your temperature in C: \n");
    scanf("%d", &cel);
    fah = cel * (9/5) + 32;
    // printf("option 1");
  }
  else if (opt == 2) {
    printf("option 2");
  }
  else {
    printf("no\n");
  };
  return 0;
}
