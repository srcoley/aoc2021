#include <stdio.h>
#include <string.h>

#define SIZE 200
#define SIG_SIZE 10
#define OUT_SIZE 4
#define UNIQ_SIZE 4
#define ENTRY_PAT "%s %s %s %s %s %s %s %s %s %s | %s %s %s %s\n"

struct entry {
  char signals[SIG_SIZE][8];
  char output[OUT_SIZE][8];
};

int main(int argc, char* argv[]) {
  int i, count = 0;
  struct entry entries[SIZE] = {0};
  int uniqSizes[] = { 2, 3, 4, 7 };

  i = 0;
  while( scanf(ENTRY_PAT,
    entries[i].signals[0],
    entries[i].signals[1],
    entries[i].signals[2],
    entries[i].signals[3],
    entries[i].signals[4],
    entries[i].signals[5],
    entries[i].signals[6],
    entries[i].signals[7],
    entries[i].signals[8],
    entries[i].signals[9],
    entries[i].output[0],
    entries[i].output[1],
    entries[i].output[2],
    entries[i].output[3]
  ) > 0 ) {
    i++;
  }

  for( int e = 0; e < SIZE; e++ ) {
    for( int o = 0; o < OUT_SIZE; o++ ) {
      for( i = 0; i < UNIQ_SIZE; i++ ) {
        if( strlen(entries[e].output[o]) == uniqSizes[i] ) {
          /* printf("%ld: %s\n", strlen(entries[e].output[o]), entries[e].output[o]); */
          count++;
        }
      }
    }
  }

  printf("results: %d\n", count);

  return 0;
}
