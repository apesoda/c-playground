#include <stdio.h>
int main(){
  int inter;
  float floating;
  double dub;
  char charac;
  printf("Integer size is: %d bytes\n", sizeof(inter));
  printf("Float size is: %d bytes\n", sizeof(floating));
  printf("Double size is: %d bytes\n", sizeof(dub));
  printf("Integer size is: %d bytes\n", sizeof(charac));
  return 0;
}
