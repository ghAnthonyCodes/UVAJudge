#include <bits/stdc++.h>
using namespace std;

int N, M;
char G[101][101];

bool isBomb(int r, int c) {
  if (r < 0 || r >= N || c < 0 || c >= M)
    return false;
  return G[r][c] == '*';
}

int countBombs(int r, int c) {
  int bombs = 0;
  bombs += isBomb(r-1, c);
  bombs += isBomb(r+1, c);
  bombs += isBomb(r, c+1);
  bombs += isBomb(r, c-1);
  bombs += isBomb(r+1, c+1);
  bombs += isBomb(r+1, c-1);
  bombs += isBomb(r-1, c+1);
  bombs += isBomb(r-1, c-1);
  return bombs;
}

int main() {

  char buff[110];
  string R;
  int field = 0;
  while (scanf("%d %d", &N, &M) != EOF) {
    if (N == 0 && M == 0)
      return 0;
    field++;
    for (int r=0; r<N; r++) {
      scanf("%s", buff);
      R = buff;
      for (int c = 0; c < M; c++)
        G[r][c] = R[c];
    }

    // Solve
    if (field > 1)
      printf("\n");
    printf("Field #%d:\n", field);
    for (int r=0; r<N; r++) {
      for (int c=0; c<M; c++) {
        if (G[r][c] == '*') 
          printf("*");
        else
          printf("%d", countBombs(r, c));
      }
      printf("\n");
    }
    /*
    for (int r=0; r<n; r++) {
      for (int c=0; c<m; c++)
        printf("%c", G[r][c]);
      printf("\n");
    }*/
  }
  return 0;
}
