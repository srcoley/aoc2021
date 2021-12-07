#include <stdio.h>
#include <stdlib.h>

#define START_SIZE 300
#define DAYS 80

struct school {
  int days;
  int size;
};

typedef struct {
  struct school *array;
  size_t used;
  size_t size;
  size_t filledSize;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(struct school));
  a->used = 0;
  a->size = initialSize;
  a->filledSize = 0;
}

void insertArray(Array *a, struct school element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(struct school));
  }
  a->array[a->used++] = element;
  a->filledSize++;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = a->filledSize = 0;
}

int main(int argc, char* argv[]) {
  int num;
  Array fish;

  initArray(&fish, START_SIZE);

  int i = 0;
  while( scanf("%d,", &num) > 0 ) {
    struct school s = { num, 1 };
    insertArray(&fish, s);
    i++;
  }

  int new = 0;
  for( int d = 0; d <= DAYS; d++ ) {
    /* if( d == 0 ) { */
    /*   printf("Initial state: "); */
    /* } else { */
    /*   printf("After %2d days: ", d); */
    /* } */

    if( new > 0 ) {
      struct school ns = { 8, new };
      insertArray(&fish, ns);
      new = 0;
    }

    for( int f = 0; f < fish.filledSize; f++ ) {
      for( int sf = 0; sf < fish.array[f].size; sf++ ) {
        /* printf("%d ", fish.array[f].days); */
      }

      if( fish.array[f].days == 0 ) {
        new += fish.array[f].size;
        fish.array[f].days = 6;
      } else {
        fish.array[f].days--;
      }
    }

    /* printf("\n"); */
  }

  long int count = 0;
  for( int f = 0; f < fish.filledSize; f++ ) {
    count += fish.array[f].size;
  }

  printf("results: %ld", count);

  freeArray(&fish);

  return 0;
}
