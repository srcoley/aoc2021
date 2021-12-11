#include <stdio.h>

#define LSIZE 128
#define SSIZE 90

#define LEFT_PAREN '('
#define RIGHT_PAREN ')'

#define LEFT_BRACKET '['
#define RIGHT_BRACKET ']'

#define LEFT_BRACE '{'
#define RIGHT_BRACE '}'

#define LEFT_CARET '<'
#define RIGHT_CARET '>'

char pair(char *c);
int left(char *c);
int right(char *c);
int ctoscore(char *c);
void qsort( long int *v, int left, int right );
void swap( long int *v, int i, int j );

int main(int argc, char* argv[]) {
  int abortline = 0;
  long int total = 0;
  long int scores[SSIZE] = {0};
  long int *scp = scores;

  char c;
  char stack[LSIZE] = {0};
  char *sp = stack;
  char line[LSIZE] = {0};
  char *lp;

  while( fgets(line, sizeof line, stdin) != NULL ) {
    for( int i = 0; i < LSIZE; i++) { stack[i] = '\0'; }

    sp = stack;
    lp = line;
    int valid = 1;
    while( sscanf(lp++, "%c", &c) == 1 ) {
      if( abortline ) {
        if( c == '\n' ) {
          abortline = 0;
        }
      } else if( left(&c) ) {
        if( sp+1 < &stack[LSIZE]) {
          *sp++ = c;
        }
      } else if( right(&c) && *(sp-1) != pair(&c)) {
        valid = 0;
        abortline = 1;
      } else if( right(&c) && *(sp-1) == pair(&c) ) {
        if( sp-1 >= stack ) {
          *--sp = 0;
        }
      }
    }

    if( valid ) {
      char fix[32] = {0};
      char *fp = fix;
      sp--;
      total = 0;
      while( sp >= stack ) {
        char end = pair(sp--);
        total *= 5;
        total += ctoscore(&end);
        *fp = end;
        fp++;
      }

      *scp++ = total;

      /* printf("%s -> %s -> %ld\n", line, fix, total); */
    }
  }

  qsort(scores, 0, SSIZE-1);

  scp = scores;

  int middle = 0;
  for( int i = 0; i < SSIZE; i++ ) {
    if( scores[i] == 0 ) {
      middle = i/2;
      break;
    }
  }

  printf("results: %ld\n", scores[middle]);
  return 0;
}

int ctoscore(char *c) {
  switch(*c) {
    case RIGHT_PAREN: return 1;
    case RIGHT_BRACKET: return 2;
    case RIGHT_BRACE: return 3;
    case RIGHT_CARET: return 4;
    default: return 0;
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

void swap( long int *v, int i, int j ) {
  long int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void qsort( long int *v, int left, int right ) {
  int i, last;

  if( left >= right) { return; }

  swap(v, left, (left+right)/2);
  last = left;
  for( i = left + 1; i <= right; i++ ) {
    if( v[i] > v[left] ) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last+1, right);
}
