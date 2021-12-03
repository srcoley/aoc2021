#include<stdio.h>
#include<math.h>

int btoi(long int n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

int main(int argc, char* argv[]) {
  int i = 0;
  int score[2];

  long int bit;
  long int mask = 0x800;
  long int gamma = 0;
  long int epsilon = 0;

  long int vals[1000];

  while( scanf("%ld\n", &vals[i++]) == 1 )
    ;

  for( int x = 0; x < 12; x++ ) {
    score[0] = 0;
    score[1] = 0;

    for( int y = 0; y < 1000; y++ ) {
      bit = (btoi(vals[y]) & mask);
      bit = bit >> (11 - x);

      score[bit]++;
    }

    if( score[0] > score[1] ) {
      epsilon = epsilon | mask;
    } else if( score[0] < score[1] ) {
      gamma = gamma | mask;
    } else {
      printf("%d: draw!\n", x);
      return -1;
    }

    mask /= 2;
  }

  printf("result: %ld", gamma*epsilon);
  return 0;
}
