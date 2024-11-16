#include <stdio.h>
#include <stdlib.h>
int main(){
  int random;
  int input;
  random = rand() % (100 - 1 + 1) + 1;
  do {
    printf("Please enter a number between 1 and 100: ");
    scanf("%d",&input);
    if (input != random) {
      printf("Nope, not it!\n");
    }
  }
  while (input != random);
  printf("That's it!\n");
  return 0;
}
