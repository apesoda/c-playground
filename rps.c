#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  char cpu_pick, usr_pick;
  srand(time(NULL)); 
  cpu_pick = "rps"[rand() % 3];
  printf("ROCK (r) PAPER (p) SCISSORS (s)\n");
  printf("%c", cpu_pick);
  scanf("%c", &usr_pick);
  if (cpu_pick == 'r') {
    if (usr_pick == 'p') {
      printf("CPU picked rock, you win! \n");
    }
    else if (usr_pick == 's') {
      printf("CPU picked rock, your loss! \n");
    }
    else if (usr_pick == cpu_pick ) {
      printf("CPU picked rock, it's a tie! \n");
    }
    else {
      printf("Not real, nobody wins >:( \n");
    };  
  }
  else if (cpu_pick == 'p') {
    if (usr_pick == 'r') {
      printf("CPU picked paper, you win! \n");
    }
    else if (usr_pick == 's') {
      printf("CPU picked paper, your loss! \n");
    }
    else if (usr_pick == cpu_pick ) {
      printf("CPU picked paper, it's a tie! \n");
    }  
    else {
      printf("Not real, nobody wins >:( \n");
    };
  }
  else if (cpu_pick == 's') {
    if (usr_pick == 'r') {
      printf("CPU picked scissors, you win! \n");
    }
    else if (usr_pick == 'p') {
      printf("CPU picked scissors, your loss! \n");
    }
    else if (usr_pick == cpu_pick ) {
      printf("CPU picked scissors, it's a tie! \n");
    }
    else {
      printf("Not real, nobody wins >:( \n");
    };  
  }
  return 0; 
}
