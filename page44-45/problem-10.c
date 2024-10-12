#include <stdio.h>
int main(){
  char asciivalue;
  printf("Enter the character you want to see the ASCII value of: ");
  scanf("%c", &asciivalue);
  printf("the ASCII value of the %c character is: %d \n", asciivalue, asciivalue);
  return 0;
}
// To compile run: gcc -o <outfile> problem-10.c
