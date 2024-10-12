#include <stdio.h>
#define PI 3.14

int main(){
  int rad;
  float pi, circ, area;
  printf("What is the radius of the circle?: ");
  scanf("%d", &rad);
  circ = 2*PI*rad;
  area = PI*rad*rad;
  printf("The circumference of the area of the circle is %0.2f and the circumference is %0.2f \n", circ, area);
  return 0;
}
