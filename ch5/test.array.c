#include <ctype.h>
#include <stdio.h>

/* p 99: 
   "By definition, the value of a variable or expression
   of type array is the address of element zero is 
   the address of element zero of the array. 
*/

int main() 
{
  int s[] = {1, 2, 3};
  int *x;
  x = s;

  
  char *pmessage;
  pmessage = "now is the time";

  printf("%c\n", *(pmessage+2));
}
