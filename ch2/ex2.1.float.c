#include <stdio.h>
#include <float.h>

int main() 
{

  /* compute range of float */

  /* find machine eps
     this finds it if it has form 1/(2^n), 
     otherwise this result is somewhere 
     between 0 and 2*eps */
  
  float x = 0.0, y0=1.0, y1=1.0;
  y1 = y0/2.0;
  while (x+y1 > x) {
    y0 = y1;
    y1 = y1/2.0;
  }
  
  printf("%f\n",y0);
  if (x+y0 == x) 
    printf("something's wrong\n");

  float e = y0;

  /* now find closest power of 2 */
  float next = 2.0, last = 2.0;
    next = next*2;
    while ( next == next ) {
    last = next; 
    next = next*2;
  }
  printf("closest power of 2: %f \n", last);
  next = last+400000000000 ;
  float zz = next - last;

  /* I gave up. 
     Not sure how to deal with inf
     Arithmetic appears to work differently for very large numbers
     eg 170141183460469231731687303715884105728.000000+4.0 = 170141183460469231731687303715884105728.000000
     Did not want to use float.h (but i did)
     

    while (next < FLT_MAX) {
    last = next;
    ++next;
  }
  printf("closest int: %f \n", last);*/
}
