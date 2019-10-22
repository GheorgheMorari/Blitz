#include<stdio.h>
#define N 8

int trackBack(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);

int safe(int x, int y, int sol[N][N]) {
  if (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
    return 1;
  return -1;
}

void printSolution(int sol[N][N]) {
  int x, y;
  for (x = 0; x < N; x++) {
    for (y = 0; y < N; y++)
      printf(" %2d ", sol[x][y]);
    printf("\n");
  }
}

int solveKT() {
  int sol[N][N];
  int x, y;
  for (x = 0; x < N; x++)
    for (y = 0; y < N; y++)
      sol[x][y] = -1;

    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 

  sol[0][0] = 0;

  if (trackBack(0, 0, 1, sol, xMove, yMove) == -1) {
    printf("Solution does not exist");
    return -1;
  } else
    printSolution(sol);

  return 1;
}

int trackBack(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]) {
  int k, next_x, next_y;
  if (movei == N * N)
    return 1;

  for (k = 0; k < 8; k++) {
    next_x = x + xMove[k];
    next_y = y + yMove[k];
    if (safe(next_x, next_y, sol) == 1) {
      sol[next_x][next_y] = movei;
      if (trackBack(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
        return 1;
      else
        sol[next_x][next_y] = -1;
    }
  }

  return -1;
}

int main() {
  solveKT();
  return 0;
}
