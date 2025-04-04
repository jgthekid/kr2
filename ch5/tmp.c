#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> 

/* unix-like toy tail program */

#define MAXLEN 1000 // max line length
#define NDEFAULT 10 // default value of n 

/* approach: keep array of n pointers, 
   loading newest line and dropping oldest at position k.
   When we hit, EOF, print from k+1 to n then 0 to k 
*/

int getLine(char *s, int max); // L: name conflict

int main(int argc, char *argv[])
{
  int n = (argc > 1) ? -atoi(argv[1]) : NDEFAULT; 
  n++ ; /* need an extra array for when we hit EOF */
  int k = 0;
  int cycle = 0; // need to check if we have at least n lines

  //  char *buf[n];
  // heavy-handed: make sure buf is big enough
  char buf[n][MAXLEN];  

  /* record n lines until finished */
  while (getLine(buf[k++], MAXLEN) > 0) {
    if (k == n) {
      cycle = 1; 
      k = 0;
    }
  }

  //  int i = (k < n) ? k : 0;
  int i = k;
  /*
  printf("buf[0]:%s", buf[0]);
  printf("buf[k]:%s", buf[k]);
  printf("buf[n]:%s", buf[n]);
  printf("i:%d k:%d\n", i, k);
  printf("----\n");
  */
  if (cycle == 1) {
    for (; i < n; i++) {
      //buf[i] = "abc\n";
      printf("%s", buf[i]);
    }
  }
  
  i = 0;
  while (i < k) {
    printf("%s", buf[i++]);
  }
  /*
  for (i = 0; i <= k; i++) {
    //buf[i] = "abc\n";
    printf("%s", buf[i]);
  }
  */
}

/* getLine: get line into s, return length, pointer version */
int getLine(char *s, int lim)
{
  int c, i;
  char *s0 = s;

  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - s0;
}
