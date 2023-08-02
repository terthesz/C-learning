#include <stdio.h>

void err(const char *message) {
  printf("%s", message);
  exit(1);
}

int scan(const char *prompt) {
  int negative = 0;
  int num = 0;
  char ch;

  printf("%s", prompt);

  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (!(ch >= '0' && ch <= '9' || ch == '-'))
      err("Invalid character. Input must contain only numbers.");

    if (ch == '-') {
      negative = 1;
      continue;
    }

    int i = ch - '0';

    if (i > 0) {
      num += i;
      continue;
    }
    num *= 10;
  };

  if (num == 0)
    err("NELZE");

  if (negative != 0)
    num = -num;

  return num;
}

int read_int(const char *prompt) {
  int num;

  printf("%s", prompt);
  scanf("%d", &num);

  return num;
}

int main(void) {
  while (1) {
    int result = (scan("Prvé číslo: ") / scan("Druhé číslo: "));
    printf("%i\n", result);
  }
}
