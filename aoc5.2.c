#include <stdio.h>
#include <math.h>

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

void fillLine( struct line *lp, int grid[HEIGHT][WIDTH]) {
  struct point diff = { lp->b.x - lp->a.x, lp->b.y - lp->a.y };
  struct point ndiff = {};
  ndiff.x = ( diff.x != 0 ) ? diff.x/(int)fabs((float)diff.x) : 0;
  ndiff.y = ( diff.y != 0 ) ? diff.y/(int)fabs((float)diff.y) : 0;

  struct point a = { lp->a.x, lp->a.y };
  while( a.x != lp->b.x || a.y != lp->b.y ) {
    grid[a.y][a.x]++;
    if( a.x != lp->b.x ) { a.x += ndiff.x; }
    if( a.y != lp->b.y ) { a.y += ndiff.y; }
  }
  grid[a.y][a.x]++;
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

  int x1, x2, y1, y2;
  struct point diff = {};
  for( ;pline < pend; pline++ ) {
    x1 = pline->a.x;
    x2 = pline->b.x;
    y1 = pline->a.y;
    y2 = pline->b.y;

    diff.x = x2-x1;
    diff.y = y2-y1;

    fillLine(pline, grid);
  }

  int intersections = 0;
  for( int y = 0; y < HEIGHT; y++ ) {
    for( int x = 0; x < WIDTH; x++ ) {
      int d = grid[y][x];
      if( d > 1 ) {
        intersections++;
        /* printf("%d", d); */
      } else if( d == 1 ) {
        /* printf("%d", d); */
      } else {
        /* printf("%c", '.'); */
      }
    }
    /* printf("\n"); */
  }

  printf("intersections: %d\n", intersections);

  return 0;
}
