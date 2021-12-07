#include <stdio.h>
#include <math.h>

#define SIZE 1000

int main(int argc, char* argv[]) {
  int crabs[SIZE];
  int *cp = crabs;

  while( scanf("%d,", cp++) > 0 )
    ;

  int i, n, diff, fuel, leastFuel = 0;
  for( i = 0; i < SIZE; i++ ) {
    fuel = 0;
    for( n = 0; n < SIZE; n++ ) {
      if( crabs[i] == crabs[n] ) { continue; }

      diff = (int) fabs((float)(crabs[i] - crabs[n]));
      fuel += diff;
    }

    if( i == 0 || fuel < leastFuel ) {
      leastFuel = fuel;
    }
  }

  // 344605
  printf("results: %d\n", leastFuel);

  return 0;
}
