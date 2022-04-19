#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define vii vector<ii>

bool wonGame(bool B[5][5]) {
  for (int r=0; r<5; r++) {
    bool won = true;
    for (int c=0; c<5; c++) 
      won &= B[r][c];
    if (won)
      return true;
  }
  for (int c=0; c<5; c++) {
    bool won = true;
    for (int r=0; r<5; r++)
      won &= B[r][c];
    if (won)
      return true;
  }
  if (B[0][0] == true && B[1][1] == true && B[3][3] == true && B[4][4] == true)
    return true;
  if (B[4][0] == true && B[3][1] == true && B[1][3] == true && B[0][4] == true)
    return true;
  return false;
}

int main() {

  int T, a;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    ii V[76] = { { 0, 0 } };
    bool Vgood[76] = { false };
    bool B[5][5] = { false };
    for (int r = 0; r < 5; r++) {
      for (int c = 0; c < 5; c++) {
        if (r == 2 && c == 2) {
          B[r][c] = true;
          continue;
        }
        scanf("%d", &a);
        V[a] = { r, c };
        Vgood[a] = true;
      }
    }

    // Read in bingo numbers
    bool alreadyWon = false;
    for (int i=1; i<=75; i++ ) {
      scanf("%d", &a);
      if (!alreadyWon) {
        if (Vgood[a]) {
          B[V[a].first][V[a].second] = true;
          if (wonGame(B)) {
            printf("BINGO after %d numbers announced\n", i);
            alreadyWon = true;
          }
        }
      }
    }
    
    

  }
  return 0;
}
