#include <stdio.h>

int main(){
  char name[13], dob[10], tel[16];
  printf("Welcome to the profile intro generator!\nPlease enter your first name: ");
  scanf("%s", name);
  printf("Please enter your date of birth (DD-MM-YYYY): ");
  scanf("%s", dob);
  printf("Please enter your mobile number: ");
  scanf("%s", tel);
  printf("\nHi everyone!\nMy name is %s, I was born on %s.\nYou can reach me by dialing %s", name, dob, tel);
  return 0;
}
// this is really ugly and there is a bug that makes it so the name only shows up under magic circumstances
// To compile run: gcc -o <outfile> problem-12.c
