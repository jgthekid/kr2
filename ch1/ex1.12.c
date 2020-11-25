#include <stdio.h>

/* print input one word per line */

#define IN 1 /* in a word */
#define OUT 0 /* outside a word */

int main() 
{
  int c, state;

  state = OUT;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN){
        printf("\n");
          }
      state = OUT;
    }
    else {
      putchar(c);
      if (state == OUT) {
        state = IN;
      }
    }
  }
}
