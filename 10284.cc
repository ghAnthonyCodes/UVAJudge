#include <bits/stdc++.h>
using namespace std;

char G[8][8];

void printBoard() {
  printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++)
      printf("%c ", G[i][j]);
    printf("\n");
  }
}

void attack(int r, int c) {
  if (r >= 0 && r < 8 && c >= 0 && c < 8) {
    if (G[r][c] == '-')
      G[r][c] = 'a';
  }
}

void kingAttack(int r, int c) {
  attack(r+1, c);
  attack(r-1, c);
  attack(r, c+1);
  attack(r, c-1);
  attack(r+1, c+1);
  attack(r+1, c-1);
  attack(r-1, c+1);
  attack(r-1, c-1);
}

void nightAttack(int r, int c) {
  attack(r-2, c+1);
  attack(r-1, c+2);
  attack(r+1, c+2);
  attack(r+2, c+1);
  attack(r+2, c-1);
  attack(r+1, c-2);
  attack(r-1, c-2);
  attack(r-2, c-1);
}

void whitePawnAttack(int r, int c) {
  attack(r-1, c-1);
  attack(r-1, c+1);
}

void blackPawnAttack(int r, int c) {
  attack(r+1, c-1);
  attack(r+1, c+1);
}

void rookAttack(int r, int c) {
  // attack up
  for (int x=r-1; x>=0; x--) {
    if (G[x][c] != '-' && G[x][c] != 'a')
      break;
    attack(x, c);
  }

  // attack down
  for (int x=r+1; x<8; x++) {
    if (G[x][c] != '-' && G[x][c] != 'a')
      break;
    attack(x, c);
  }

  // attack left
  for (int x=c-1; x >= 0; x--) {
    if (G[r][x] != '-' && G[r][x] != 'a')
      break;
    attack(r, x);
  }

  // attack right
  for (int x=c+1; x < 8; x++) {
    if (G[r][x] != '-' && G[r][x] != 'a')
      break;
    attack(r, x);
  }
}

void bishopAttack(int r, int c) {
  // Top left
  int x = r-1;
  int y = c-1;
  while (x >=0 && y >= 0 && (G[x][y] == '-' || G[x][y] == 'a'))
    attack(x--, y--);

  // Top right
  x = r-1;
  y = c+1;
  while (x >=0 && y < 8 && (G[x][y] == '-' || G[x][y] == 'a'))
    attack(x--, y++);

  // Bottom left
  x = r+1;
  y = c-1;
  while (x < 8 && y >= 0 && (G[x][y] == '-' || G[x][y] == 'a'))
    attack(x++, y--);

  // Bottom right
  x = r+1;
  y = c+1;
  while (x < 8 && y < 8 && (G[x][y] == '-' || G[x][y] == 'a'))
    attack(x++, y++);
}

int main() {
  char fen[500];
  string fenS;
  while (scanf("%s\n", fen) != EOF) {
    fenS = fen;
    int row=0; int col=0;
    for (int i=0; i<fenS.length(); i++) {

      // Handle empty spaces
      if (fenS[i] <= '9' && fenS[i] >= '0') {
        for (int k=0; k<fenS[i]-'0'; k++) {
          G[row][col] = '-';
          col++;
        }
      } else if (fenS[i] == '/') {
        row++;
        col = 0;
      } else {
        G[row][col] = fenS[i];
        col++;
      }
    }
    // printBoard();

    // For each piece, simulate attacks
    for (int r=0; r<8; r++) {
      for (int c=0; c<8; c++) {

        // Sim king movement
        if (G[r][c] == 'k' || G[r][c] == 'K')
          kingAttack(r, c); 
        else if (G[r][c] == 'n' || G[r][c] == 'N') 
          nightAttack(r, c);
        else if (G[r][c] == 'P')
          whitePawnAttack(r, c);
        else if (G[r][c] == 'p')
          blackPawnAttack(r, c);
        else if (G[r][c] == 'R' || G[r][c] == 'r')
          rookAttack(r, c);
        else if (G[r][c] == 'b' || G[r][c] == 'B') 
          bishopAttack(r, c);
        else if (G[r][c] == 'Q' || G[r][c] == 'q') {
          rookAttack(r, c);
          bishopAttack(r, c);
        }
      }
    }
    // printBoard();

    int ans = 0;
    for (int i=0; i<8; i++) {
      for (int j=0; j<8; j++) {
        if (G[i][j] == '-')
          ans++;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
