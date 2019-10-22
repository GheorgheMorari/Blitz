#include <stdio.h>
#define N 20

void printSolution(int board[N][N]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
}

int safe(int board[N][N], int row, int col) {
  int i, j;
  for (i = 0; i < col; i++) {
    if (board[row][i])
      return -1;
  }
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j])
      return -1;
  }

  for (i = row, j = col; j >= 0 && i < N; i++, j--) {
    if (board[i][j])
      return -1;
  }

  return 1;
}

int solveUtil(int board[N][N], int col) {
  int i;
  if (col >= N)
    return 1;
  for (i = 0; i < N; i++) {
    if (safe(board, i, col) == 1) {
      board[i][col] = 1;
      if (solveUtil(board, col + 1) == 1)
        return 1;
      board[i][col] = 0;
    }
  }
  return -1;
}

int solve() {
  int board[N][N] = {
    0
  };
  if (solveUtil(board, 0) == -1) {
    printf("No solution");
    return 1;
  }
  printSolution(board);
  return 1;
}

int main() {
  solve();
  return 0;
}
