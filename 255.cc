#include <bits/stdc++.h>
using namespace std;

#define vc vector<char>
#define vvc vector<vc>

void printG(vvc G) {
  for (auto& i : G) {
    for (auto& j : i)
      printf("%c ", j);
    printf("\n");
  }
}

int main() {
  int A, B, C;
  while (scanf("%d %d %d", &A, &B, &C) != EOF) {
    vvc G = vvc(8, vc(8, '-'));
    if (A == B) {
      printf("Illegal state\n");
      continue;
    }

    int kingRow = A / 8;
    int kingCol = A % 8;
    int queenRow = B / 8;
    int queenCol = B % 8;
    int moveRow = C / 8;
    int moveCol = C % 8;

    // Put pieces on the board
    G[kingRow][kingCol] = 'K';
    G[queenRow][queenCol] = 'Q';

    // printG(G);

    if (moveCol != queenCol && moveRow != queenRow || B == C || A == C) {
      printf("Illegal move\n");
      continue;
    }

    // Check for king collision
    bool illegalMove = false;
    if (moveRow == queenRow) {
      if (queenCol < moveCol) {
        for (int x = queenCol; x<moveCol; x++) {
          if (G[moveRow][x] == 'K') {
            illegalMove = true;
          }
        }
      } else {
        for (int x = queenCol; x>moveCol; x--) {
          if (G[moveRow][x] == 'K') {
            illegalMove = true;
          }
        }
      }
    }

    if (moveCol == queenCol) {
      if (queenRow < moveRow) {
        for (int x = queenRow; x<moveRow; x++) {
          if (G[x][moveCol] == 'K') {
            illegalMove = true;
          }
        }
      } else {
        for (int x = queenRow; x>moveRow; x--) {
          if (G[x][moveCol] == 'K') {
            illegalMove = true;
          }
        }
      }
    }

    if (illegalMove) {
      printf("Illegal move\n");
      continue;
    }

    // disallowable moves
    G[min(7, max(0, kingRow+1))][min(7, max(0, kingCol))] = 'n';
    G[min(7, max(0, kingRow-1))][min(7, max(0, kingCol))] = 'n';
    G[min(7, max(0, kingRow))][min(7, max(0, kingCol+1))] = 'n';
    G[min(7, max(0, kingRow))][min(7, max(0, kingCol-1))] = 'n';

    // Now check if move has an n
    // printG(G);
    // printf("M = %c\n", G[moveRow][moveCol]);
    if (G[moveRow][moveCol] != '-') {
      printf("Move not allowed\n");
      continue;
    }

    // Move the queen
    G[queenRow][queenCol] = '-';
    G[moveRow][moveCol] = 'Q';

    if (moveRow == 1 && moveCol == 1 && kingRow == 0 && kingCol == 0) {
      printf("Stop\n");
      continue;
    }

    if (moveRow == 1 && moveCol == 6 && kingRow == 0 && kingCol == 7) {
      printf("Stop\n");
      continue;
    }

    if (moveRow == 6 && moveCol == 1 && kingRow == 7 && kingCol == 0) {
      printf("Stop\n");
      continue;
    }

    if (moveRow == 6 && moveCol == 6 && kingRow == 7 && kingCol == 7) {
      printf("Stop\n");
      continue;
    }
    printf("Continue\n");

  }
  return 0;
}
