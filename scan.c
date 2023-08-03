#include <stdio.h>

void err(const char *message) {
  printf("%s", message);
  exit(1);
}

long int scan(char *is_eof) {
  long int num = 0;
  char negative = 0;
  char ch;

  while ((ch = getchar()) != '\n') {
    if (ch == EOF) {
      *is_eof = 1;
      break;
    }

    num *= 10;

    if (!(ch >= '0' && ch <= '9' || ch == '-'))
      err("Invalid character. Input must be numeric.");

    if (ch == '-') {
      negative = 1;
      continue;
    }

    num += ch - '0';
  }

  if (negative != 0)
    num = -num;

  return num;
}