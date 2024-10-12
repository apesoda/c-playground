#include <stdio.h>

int main(){
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  if (age<18){
    printf("Sorry, you are not eligible for vaccination.\n");
  }
  else{
    printf("Congratulations, you are eligible for vaccination. \n");
  }
  return 0;
}

// To compile run: gcc -o <outfile> vac.c
