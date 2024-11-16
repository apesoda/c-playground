#include <stdio.h>
#include <stdlib.h>
int main(){
  int random;
  int input;
  random = rand() % 1 + 1;
  printf("Please enter a number between 1 and 100: ");
  scanf("%d",&input);
  if (input == random){
    printf("You guessed it!\n");
  } else {
    printf("Oops, wrong!\n");
  };
  return 0;
}
