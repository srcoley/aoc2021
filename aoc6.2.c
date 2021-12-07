#include <stdio.h>

#define DAYS 256

int main(int argc, char* argv[]) {
  // fish by days
  long int fbd[9] = {0};
  long int offspring;

  int num;
  while( scanf("%d,", &num) > 0 ) {
    fbd[num]++;
  }

  for( int d = 0; d < DAYS; d++ ) {
    offspring = fbd[0];
    fbd[0] -= fbd[0]; // 0 clear

    for( int b = 0; b < 8; b++ ) {
      fbd[b] += fbd[b+1]; // 1 -> 0
      fbd[b+1] -= fbd[b+1]; // 1 clear
    }

    fbd[6] += offspring; // 0 -> 6 (parent)
    fbd[8] += offspring; // 0 -> 8 (children)
  }

  long int count = 0;
  for( int i = 0; i < 9; i++ ) {
    count += fbd[i];
  }

  printf("results: %ld\n", count);

  return 0;
}
