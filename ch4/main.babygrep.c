#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int strindex(char source[], char searchfor[]);
int getLine(char line[], int max);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */

int main()
{
  char line[MAXLINE];
  int found = 0;
  
  while (getLine(line, MAXLINE) > 0) {
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  }
  return found;
}

