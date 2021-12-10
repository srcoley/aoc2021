#include <stdio.h>

#define COLS 100
#define ROWS 100
#define SIZE 10000
#define BASIN_EDGE 9

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

void basin(int i, int xi, int *count);
int lowest(int i);
void qsort( int *v, int left, int right );
void swap( int *v, int i, int j );

int heights[SIZE] = {0};
int lowests[SIZE] = {0};
int basins[SIZE] = {0};
int counts[SIZE] = {0};

int main(int argc, char* argv[]) {
  int *hp = heights;

  FILE *fp = fopen("input/9.txt", "r");

  while( fscanf(fp, "%1d,", hp++) > 0 )
    ;

  fclose(fp);

  for( int i = 0; i < SIZE; i++ ) {
    if( lowest(i) ) {
      lowests[i] = 1;

      basin(i, -1, &counts[i]);
    }
  }

  for( int i = 0; i < SIZE; i++ ) {
    if( lowests[i] ) {
      printf(ANSI_COLOR_RED);
      printf("%d", heights[i]);
      printf(ANSI_COLOR_RESET);
    } else
    if( basins[i] ) {
      printf(ANSI_COLOR_YELLOW);
      printf("%d", heights[i]);
      printf(ANSI_COLOR_RESET);
    } else {
      printf("%d", heights[i]);
    }
    if( (i+1) % COLS == 0 ) {
      printf("\n");
    }
  }

  qsort((void *)&counts, 0, SIZE-1);

  printf("results: %d\n", counts[0] * counts[1] * counts[2]);
  return 0;
}

void basin( int i, int xi, int *count ) {
  if( heights[i] == BASIN_EDGE ) { return; }

  basins[i] = 1;
  (*count)++;

  // left sib
  int left = i-1;
  if( i % COLS != 0 && left != xi && !basins[left] ) {
    basin(left, i, count);
  }

  // right sib
  int right = i+1;
  if( (i+1) % COLS != 0 && right != xi && !basins[right] ) {
    basin(right, i, count);
  }

  // top sibling
  int top = i-COLS;
  if( i >= COLS && top != xi && !basins[top] ) {
    basin(top, i, count);
  }

  // bottom sib
  int bottom = i+COLS;
  if( i < (SIZE-COLS) && bottom != xi && !basins[bottom] ) {
    basin(bottom, i, count);
  }
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
  if( i < (SIZE-COLS) && heights[i] >= heights[i+COLS] ) {
    result = 0;
  }

  return result;
}

void swap( int *v, int i, int j ) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void qsort( int *v, int left, int right ) {
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
