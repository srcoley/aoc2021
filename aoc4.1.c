#include <stdio.h>
#include <string.h>

void printboard(int (*b)[5][5]) {
  for( int y = 0; y < 5; y++ ) {
    for( int x = 0; x < 5; x++ ) {
      printf("%d ", (*b)[y][x]);
    }
    printf("\n");
  }
}

int rowBingo(int (*bp)[5][5]) {
  for( int y = 0; y < 5; y++) {
    if( (*bp)[y][0] == -1
    &&  (*bp)[y][1] == -1
    &&  (*bp)[y][2] == -1
    &&  (*bp)[y][3] == -1
    &&  (*bp)[y][4] == -1 ) {
      return 1;
    }
  }

  return 0;
}

int colBingo(int (*bp)[5][5]) {
  for( int x = 0; x < 5; x++) {
    if( (*bp)[0][x] == -1
    &&  (*bp)[1][x] == -1
    &&  (*bp)[2][x] == -1
    &&  (*bp)[3][x] == -1
    &&  (*bp)[4][x] == -1 ) {
      return 1;
    }
  }

  return 0;
}

void applyNum(int num, int (*b)[100][5][5]) {
  for( int z = 0; z < 100; z++ ) {
    for( int y = 0; y < 5; y++ ) {
      for( int x = 0; x < 5; x++ ) {
        if( num == (*b)[z][y][x] ) {
          (*b)[z][y][x] = -1;
        }
      }
    }
  }
}

int checkBingo(int (*boards)[100][5][5]) {
  for( int z = 0; z < 100; z++ ) {
    if( rowBingo((int (*)[5][5])boards+z) || colBingo((int (*)[5][5])boards+z) ) {
      return z;
    }
  }
  return -1;

}

int boardSum(int (*b)[5][5]) {
  int x, y, total = 0;
  for( int i = 0; i < 25; i++ ) {
    x = i % 5;
    y = i / 5;
    if( (*b)[y][x] >= 0 ) {
      total += (*b)[y][x];
    }
  }
  return total;
}

int main(int argc, char* argv[]) {
  int bingo = -1;
  int num;
  char *token;
  char numStr[512];
  int boards[100][5][5] = {0};

  if( scanf("%s\n", numStr) != 1 ) {
    perror("Couldn't fetch numbers");
    return -1;
  }

  for( int z = 0; z < 100; z++ ) {
    for( int y = 0; y < 5; y++ ) {
      scanf("%d %d %d %d %d\n",
        &boards[z][y][0],
        &boards[z][y][1],
        &boards[z][y][2],
        &boards[z][y][3],
        &boards[z][y][4]);
    }
  }

  token = strtok(numStr, ",");
  while( token != NULL ) {
    sscanf(token, "%d", &num);

    applyNum(num, &boards);

    if( (bingo = checkBingo(&boards)) >= 0 ) {
      printf("BINGO!\n");
      printf("number: %d\n", num);
      printf("board: %d\n", bingo);
      printboard(boards + bingo);

      int sum = boardSum(&boards[bingo]);

      printf("board sum: %d\n", sum);
      printf("result: %d x %d = %d\n", num, sum, num * sum);
      return 0;
    }

    token = strtok(NULL, ",");
  }

  // num: 51
  //
  // 54 97 46 33 90
  // -1 -1 -1 -1 -1
  // 83 53 34 29 -1
  // 35 -1 -1 82 9
  // 56 -1 19 49 15
  //
  // result: 39984

  return 1;
}
