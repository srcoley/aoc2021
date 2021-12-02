#include <stdio.h>

struct tuple {
  int a,b,c;
};

int main(int argc, char* argv[]) {

  int i = 0;
  int r,n,c = 0;
  int list[2000];
  struct tuple t;
  struct tuple lastt;

  while( (r = scanf("%d", &n)) && r != 0 && r != EOF ) {
    list[i++] = n;
  }

  i = 0;
  while( i < 2000 ) {
    if( i+1 >= 2000 || i+2 >= 2000 ) { break; }

    t = (struct tuple) {
      list[i],
      list[i+1],
      list[i+2]
    };

    if( i > 0 && (t.a + t.b + t.c) > (lastt.a + lastt.b + lastt.c) ) {
      ++c;
    }

    lastt = t;
    ++i;
  }

  printf("result: %d\n", c);

  return 0;
}

