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
  if (usr_pick == cpu_pick) {
    printf("Tie-breaker! \n");
  }
  else {
    printf("Not a tie\n");
  }
  return 0;
}
