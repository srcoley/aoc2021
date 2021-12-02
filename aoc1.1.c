#include <stdio.h>

int main(int argc, char* argv[]) {

  int i;
  int n;
  int lastn = 0;
  int count = 0;
  while( (i = scanf("%d", &n)) && i != 0 && i != EOF ) {
    if( lastn > 0 && n > lastn ) { ++count; }

    lastn = n;
  }

  printf("result: %d\n", count);

  return 0;
}
