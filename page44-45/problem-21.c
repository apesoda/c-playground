#include <stdio.h>

int main(){
  int num, cub;
  printf("Please enter a number: ");
  scanf("%d", &num);
  cub = num * num * num;
  printf("%d cubed is %d \n", num, cub);
  return 0;
}

// To compile run: gcc -o <outfile> problem-21.c
