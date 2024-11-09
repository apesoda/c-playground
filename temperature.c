#include <stdio.h>

int main() {
  char opt;
  float cel, fah;
  printf("## CONVERT YOUR TEMPS ##\n(1) C->F\n(2) F->C\n(q) Quit\nConvert from Celsius to Fahrenheit?(1) Or from Fahrenheit to Celsius?(2): ");
  scanf("%c", &opt);
  if (opt == '1') {
    printf("Enter your temperature in C: ");
    scanf("%f", &cel);
    fah = cel * (9.0/5.0) + 32;
    printf("%0.1f degrees Celsius is %0.1f degrees Fahrenheit \n", cel, fah);
  }
  else if (opt == '2') {
    printf("Enter your temperature in F: ");
    scanf("%f", &fah);
    cel = (fah - 32) * (5.0/9.0);
    printf("%0.1f degrees Fahrenheit is %0.1f degrees Celsius \n", fah, cel);
  }
  else if (opt == 'q') {
    return 0;
  }
  else {
    printf("You just had to do it, didn't you?\n");
  };
  return 0;
}
