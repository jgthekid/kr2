#include <stdio.h>

/* fold long lines */
#define MAXLINE 1000 /* maximum input line size */

int getFoldedLine(char line[], int maxline);
int n = 20; /* max line size before inserting \n */


int main()
{
  int len;  /* current line length */ 
  int max;  /* max length seen so far */

  char line[MAXLINE];  /* current input line */
  
  max = 0;
  while ((len = getFoldedLine(line, MAXLINE)) >0)
    printf("%s", line);
}

/* modified getLine to fold long lines into several */
int getFoldedLine(char s[], int lim)
{
  extern int n;
  int c, i, j;
  j = 0;
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
    s[i] = c;
    ++j;
    if (j == n) {
      ++i; /* incrementing i inside loop could be dangerous */
      s[i] = '\n';
      j = 0;
    }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

