#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  int x = 0;
  int y = 0;

  int r;
  int units;
  char axis[8];
  while( (r = scanf("%s %d", axis, &units)) && r != 0 && r != EOF ) {
    if( strcmp(axis, "forward") == 0 ) {
      x += units;
    } else if( strcmp(axis, "down") == 0 ) {
      y += units;
    } else if( strcmp(axis, "up") == 0 ) {
      y -= units;
    }
  }

  printf("result: %d\n", x*y);

  return 0;
}

