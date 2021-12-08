#include <stdio.h>
#include <string.h>

#define SIZE 200
#define NSIG 10
#define SSIG 8
#define OUT_SIZE 4
#define UNIQ_SIZE 4

struct entry {
  char sigs[NSIG][SSIG];
  char outs[OUT_SIZE][SSIG];
};

int hasChars(char *a, char *b);
int sigMatch(char *a, char *b);
void minusChars(char *dest, char *src, char *remove);

int main(int argc, char* argv[]) {
  int i, strn, total = 0;
  char *sigp;
  char fourpart[3] = {0};
  char key[NSIG][SSIG] = {0};
  struct entry entries[SIZE] = {0};
  struct entry *ep;

  for( int i = 0; i < SIZE; i++ ) {
    ep = &entries[i];

    scanf("%s %s %s %s %s %s %s %s %s %s | %s %s %s %s\n",
      ep->sigs[0], ep->sigs[1], ep->sigs[2], ep->sigs[3], ep->sigs[4],
      ep->sigs[5], ep->sigs[6], ep->sigs[7], ep->sigs[8], ep->sigs[9],
      ep->outs[0], ep->outs[1], ep->outs[2], ep->outs[3]
    );
  }

  for( int e = 0; e < SIZE; e++ ) {
    for( int s = 0; s < NSIG; s++ ) {
      sigp = entries[e].sigs[s];
      strn = strlen(sigp);

      if( strn == 2 ) {
        memcpy(key[1], sigp, SSIG);
      } else if( strn == 3 ) {
        memcpy(key[7], sigp, SSIG);
      } else if( strn == 4 ) {
        memcpy(key[4], sigp, SSIG);
      } else if( strn == 7 ) {
        memcpy(key[8], sigp, SSIG);
      }
    }

    minusChars(fourpart, key[4], key[1]);

    for( int s = 0; s < NSIG; s++ ) {
      sigp = entries[e].sigs[s];
      strn = strlen(sigp);

      if( sigMatch(sigp, key[1]) || sigMatch(sigp, key[7])
      ||  sigMatch(sigp, key[4]) || sigMatch(sigp, key[8])) {
        continue;
      }

      int target;
      if( strn == 5 ) {
        target = hasChars(sigp, key[1]) ? 3 : hasChars(sigp, fourpart) ? 5 : 2;
        memcpy(key[target], sigp, SSIG);
      } else if( strn == 6 ) {
        target = hasChars(sigp, key[4]) ? 9 : hasChars(sigp, fourpart) ? 6 : 0;
        memcpy(key[target], sigp, SSIG);
      }
    }

    char val[5];
    for( int o = 0; o < OUT_SIZE; o++ ) {
      for( i = 0; i < 10; i++ ) {
        if( sigMatch(entries[e].outs[o], key[i]) ) {
          val[o] = i + '0';
          break;
        }
      }
    }

    int subtotal;
    if( sscanf(val, "%d", &subtotal) ) {
      total += subtotal;
    }
  }

  // 986179
  printf("results: %d\n", total);

  return 0;
}

int hasChars(char *h, char *n) {
  for( int i = 0; i < SSIG; i++ ) {
    if( n[i] == '\0' ) { break; }
    int found = 0;
    for( int s = 0; s < strlen(h); s++ ) {
      if( n[i] == h[s] ) {
        found = 1;
        break;
      }
    }
    if( !found ) { return 0; }

  }
  return 1;
}

void minusChars(char *dest, char *src, char *remove) {
  for( int i = 0; i < strlen(src); i++ ) {
    if( src[i] == '\0' ) { break; }

    int match = 0;
    for( int s = 0; s < strlen(remove); s++ ) {
      if( remove[s] == '\0' ) { break; }
      if( src[i] == remove[s] ) { match++; }
    }
    if( !match ) {
      *dest++ = src[i];
    }
  }
}

int sigMatch(char *a, char *b) {
  if( strlen(a) != strlen(b) ) { return 0; }
  return hasChars(a, b);
}
