#include <limits.h>
#include <stdio.h>
#include <math.h>

#define SIZE 1000

int main(int argc, char* argv[]) {
  int crabs[SIZE];
  int *cp = crabs;

  int min = INT_MAX;
  int max = INT_MIN;

  int i, n, diff, fuel, leastFuel = 0;

  while( scanf("%d,", cp++) > 0 )
    ;

  for( int i = 0; i < SIZE; i++ ) {
    if( crabs[i] < min ) { min = crabs[i]; }
    if( crabs[i] > max ) { max = crabs[i]; }
  }

  for( i = min; i <= max; i++ ) {
    fuel = 0;
    for( n = 0; n < SIZE; n++ ) {
      if( crabs[n] == i ) { continue; }

      diff = (int) fabs((float)(i - crabs[n]));
      for( int f = 0; f < diff; f++ ) {
        fuel += f+1;
      }
    }

    if( i == 0 || fuel < leastFuel ) {
      leastFuel = fuel;
    }
  }

  // 93699985
  printf("results: %d\n", leastFuel);

  return 0;
}
