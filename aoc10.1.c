#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

#define SIZE 10000

#define LEFT_PAREN '('
#define RIGHT_PAREN ')'

#define LEFT_BRACKET '['
#define RIGHT_BRACKET ']'

#define LEFT_BRACE '{'
#define RIGHT_BRACE '}'

#define LEFT_CARET '<'
#define RIGHT_CARET '>'

char pair(char *c) {
  switch(*c) {
    case LEFT_PAREN: return RIGHT_PAREN;
    case RIGHT_PAREN: return LEFT_PAREN;
    case LEFT_BRACKET: return RIGHT_BRACKET;
    case RIGHT_BRACKET: return LEFT_BRACKET;
    case LEFT_BRACE: return RIGHT_BRACE;
    case RIGHT_BRACE: return LEFT_BRACE;
    case LEFT_CARET: return RIGHT_CARET;
    case RIGHT_CARET: return LEFT_CARET;
    default: return *c;
  }
}

int left(char *c) {
  return *c == LEFT_PAREN
    ||  *c == LEFT_BRACKET
    ||  *c == LEFT_BRACE
    ||  *c == LEFT_CARET;
}

int right(char *c) {
  return *c == RIGHT_PAREN
    ||  *c == RIGHT_BRACKET
    ||  *c == RIGHT_BRACE
    ||  *c == RIGHT_CARET;
}

int ctoscore(char *c) {
  switch(*c) {
    case RIGHT_PAREN: return 3;
    case RIGHT_BRACKET: return 57;
    case RIGHT_BRACE: return 1197;
    case RIGHT_CARET: return 25137;
    default: return 0;
  }
}

int main(int argc, char* argv[]) {
  char c;
  char chars[SIZE];
  char *cp = chars;
  int total = 0, abortline = 0;

  char stack[SIZE/2];
  char *sp = stack;

  while( (c = getchar()) != EOF ) {
    if( abortline ) {
      printf("%c", c);
      if( c == '\n' ) {
        abortline = 0;
      }
    } else if( left(&c) ) {
      printf("%c", c);
      *cp++ = *sp++ = c;
    } else if( right(&c) && *(sp-1) != pair(&c)) {
      printf(ANSI_COLOR_RED);
      printf("%c", c);
      printf(ANSI_COLOR_RESET);
      total += ctoscore(&c);
      abortline = 1;
    } else if( right(&c) && *(sp-1) == pair(&c) ) {
      printf("%c", c);
      sp--;
    } else {
      printf("%c", c);
    }
  }

  printf("results: %d\n", total);
  return 0;
}
