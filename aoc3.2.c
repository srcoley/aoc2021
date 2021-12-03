#include<stdio.h>
#include<string.h>
#include<math.h>

int asize(long int *arr) {
  int i = 0;
  while( i < 1000 && arr[i] != 0 ) {
    i++;
  }
  return i;
}

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

void cpy(long int dest[], long int src[], int size) {
  for( int i = 0; i < size; i++ ) {
    dest[i] = src[i];
  }
}

int filter(long int bin[], int mostCommon ) {
  long int val;
  long int bit;
  long int mask = 0x800;
  int score[2] = {0};
  long int bins[2][1000] = {0};

  for( int x = 0; x < 12; x++ ) {
    score[0] = 0;
    score[1] = 0;

    int bin0 = 0, bin1 = 0;
    for( int y = 0; y < 1000; y++ ) {
      if( bin[y] == 0 ) { break; }
      val = btoi(bin[y]);
      bit = (val & mask);
      bit = bit >> (11 - x);

      if( bit == 0 ) {
        bins[0][bin0++] = bin[y];
      } else if( bit == 1 ) {
        bins[1][bin1++] = bin[y];
      } else {
        printf("edgecase!\n");
      }

      score[bit]++;
    }

    long int *p;
    if( score[0] > score[1] ) {
      p = mostCommon ? bins[0] : bins[1];
    } else if( score[0] < score[1] ) {
      p = mostCommon ? bins[1] : bins[0];
    } else {
      p = mostCommon ? bins[1] : bins[0];
    }

    if( asize(p) < 1 ) {
      break;
    }

    memset(bin, 0, sizeof(&bin));
    cpy(bin, p, 1000);

    memset(bins[0], 0, sizeof(bins[0]));
    memset(bins[1], 0, sizeof(bins[1]));

    mask /= 2;
  }

  return 0;
}

int main(int argc, char* argv[]) {
  int i = 0;
  long int vals[1000] = {0};
  long int Ogr[1000] = {0};
  long int C02sr[1000] = {0};

  while( scanf("%ld\n", &vals[i++]) == 1 )
    ;

  cpy(Ogr, vals, 1000);
  cpy(C02sr, vals, 1000);

  filter(Ogr, 1);
  filter(C02sr, 0);

  printf("result: %d", btoi(Ogr[0])*btoi(C02sr[0]));
  return 0;
}
