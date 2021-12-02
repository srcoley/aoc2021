#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void runp(char *);

int main(int argc, char* argv[]) {
  if( argc != 2 ) {
    printf("usage: run [num] (ex. run 1.1)\n");
    return 1;
  } else if( strcmp(argv[1], "all") == 0 ) {
    char ver[5];
    for( int i = 0; i < 31; i++ ) {
      sprintf(ver, "%d.%d", i, 1);
      runp(ver);
      sprintf(ver, "%d.%d", i, 2);
      runp(ver);
    }
  } else {
    runp(argv[1]);
  }

  return 0;
}

void runp( char *version ) {
  char name[8];
  sprintf(name, "aoc%s", version);

  if( access(name, F_OK) != 0 ) { return; }

  char input[3] = "";
  char *sep = strstr(version, ".");
  strncpy(input, version, sep-version);

  char cmd[30] = "";
  sprintf(cmd, "cat input/%s.txt | ./%s", input, name);

  printf("%s\n", cmd);

  system(cmd);
  printf("\n");
}
