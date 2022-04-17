#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, A, B, C, x, y, roll, turn;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int G[101] = { 0 };
    int L[101] = { 0 };
    scanf("%d %d %d", &A, &B, &C);
    for (int b=0; b<B; b++) {
      scanf("%d %d", &x, &y);
      L[x] = y;
    }
    vector<int> players = vector<int>(A, 1);
    bool done = false;
    for (int c=0; c<C; c++) {
      turn = c % A;
      scanf("%d", &roll);
      if (!done) {
        players[turn] = min(players[turn] + roll, 100);
        if (L[players[turn]] != 0)
          players[turn] = L[players[turn]];
        if (players[turn] == 100) {
          done = true;
        }
      }
    }

    for (int i=0; i<players.size(); i++) {
      printf("Position of player %d is %d.\n", i+1, players[i]);
    }
  }
  return 0;
}
