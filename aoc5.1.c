#include <stdio.h>

#define SIZE 500
#define WIDTH 1000
#define HEIGHT 1000

struct point {
  int x, y;
};

struct line {
  struct point a;
  struct point b;
};

void filllinex( struct line *lp, int grid[HEIGHT][WIDTH]) {
  int x1 = lp->a.x;
  int x2 = lp->b.x;
  int y  = lp->a.y;

  if( x1 < x2 ) {
    for( int x = x1; x <= x2; x++ ) {
      grid[y][x]++;
    }
  } else {
    for( int x = x1; x >= x2; x-- ) {
      grid[y][x]++;
    }
  }
}

void fillliney( struct line *lp, int grid[HEIGHT][WIDTH]) {
  int  x = lp->a.x;
  int y1 = lp->a.y;
  int y2 = lp->b.y;

  if( y1 < y2 ) {
    for( int y = y1; y <= y2; y++ ) {
      grid[y][x]++;
    }
  } else {
    for( int y = y1; y >= y2; y-- ) {
      grid[y][x]++;
    }
  }
}

int main(int argc, char* argv[]) {
  int grid[HEIGHT][WIDTH] = {0};
  struct line lines[SIZE];
  struct line *pline = lines;
  struct line *pend = lines + SIZE;

  int i = 0;
  while( scanf("%d,%d -> %d,%d\n", &lines[i].a.x, &lines[i].a.y, &lines[i].b.x, &lines[i].b.y) > 0 ) {
    i++;
  }

  for( ;pline < pend; pline++ ) {
    if( pline->a.x == pline->b.x ) {
      fillliney(pline, grid);
    } else if( pline->a.y == pline->b.y ) {
      filllinex(pline, grid);
    }
  }

  int intersections = 0;
  for( int y = 0; y < HEIGHT; y++ ) {
    for( int x = 0; x < WIDTH; x++ ) {
      if( grid[y][x] > 1 ) { intersections++; }
    }
  }

  printf("intersections: %d\n", intersections);

  return 0;
}
