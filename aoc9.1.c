#include <stdio.h>
#include <math.h>

#define COLS 100
#define ROWS 100
#define SIZE 10000

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

int lowest(int i);

int heights[SIZE] = {0};

int main(int argc, char* argv[]) {
  int *hp = heights;

  FILE *fp = fopen("input/9.txt", "r");

  while( scanf("%1d,", hp++) > 0 )
    ;

  fclose(fp);

  long int total = 0;
  for( int i = 0; i < SIZE; i++ ) {
    if( lowest(i) ) {
      total += (heights[i] + 1);
      printf(ANSI_COLOR_RED);
      printf("%d", heights[i]);
      printf(ANSI_COLOR_RESET);
    } else {
      printf("%d", heights[i]);
    }
    if( (i+1) % COLS == 0 ) {
      printf("\n");
    }
  }

  printf("results: %ld\n", total);
  return 0;
}

int lowest( int i ) {
  int result = 1;

  // left sib
  if( i % COLS != 0 && heights[i] >= heights[i-1] ) {
    result = 0;
  }

  // right sib
  if( (i+1) % COLS != 0 && heights[i] >= heights[i+1] ) {
    result = 0;
  }

  // top sibling
  if( i >= COLS && heights[i] >= heights[i-COLS] ) {
    result = 0;
  }

  // bottom sib
  if( i <= (SIZE-COLS+1) && heights[i] >= heights[i+COLS] ) {
    result = 0;
  }

  return result;
}
