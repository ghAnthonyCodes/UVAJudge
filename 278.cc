#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

int placeQueen(vvi G, int x, int y) {

  // Place the queen
  for (int r=0; r<G.size(); r++)
    G[r][y] = 1;

  for (int c=0; c<G[0].size(); c++)
    G[x][c] = 1;

  // Do diagonal, to top left
  int tlR = x, tlC = y;
  while (tlR >= 0 && tlC >= 0) {
    G[tlR][tlC] = 1;
    tlR--;
    tlC--;
  }

  // Do diagonal, to top right 
  int trR = x, trC = y;
  while (trR >= 0 && trC < G[0].size()) {
    G[trR][trC] = 1;
    trR--;
    trC++;
  }

  // Do diagonal, to bottom left
  int blR = x, blC = y;
  while (blR < G.size() && blC >= 0) {
    G[blR][blC] = 1;
    blR++;
    blC--;
  }

  // Do diagonal, to bottom right 
  int brR = x, brC = y;
  while (brR < G.size() && brC < G[0].size()) {
    G[brR][brC] = 1;
    brR++;
    brC++;
  }
  G[x][y] = 2;
  
  /*
  printf("Placed %d %d\n", x, y);
  for (int r = 0; r < G.size(); r++) {
    for (int c = 0; c < G[0].size(); c++)
      printf("%d ", G[r][c]);
    printf("\n");
  }*/

  // Place queen for next row
  if (x+1 == G.size()) {
    return 1;
  }

  // Else find where to put queen
  int tmp = 0;
  for (int col = 0; col < G[0].size(); col++) {
    if (G[x+1][col] == 0)
      tmp = max(tmp, placeQueen(G, x+1, col));
  }
  return 1 + tmp;
}

int main() {

  int T, M, N;
  char P[10];
  scanf("%d", &T);
  while (T--) {
    scanf("%s %d %d", P, &M, &N);

    // Rook case
    if (P[0] == 'r') {
      printf("%d\n", min(M, N));
      continue;
    }

    if (P[0] == 'k') {
      printf("%d\n", (M*N+1)/2);
      continue;
    }

    if (P[0] == 'Q') {
      vvi G = vvi(M, vi(N, 0));
      int m = 0;
      for (int n=0; n<G[0].size(); n++)
        m = max(m, placeQueen(G, 0, n));
      printf("%d\n", m);
      continue;
    }

    if (P[0] == 'K') {
      printf("%d\n", ((M+1)/2)*((N+1)/2));
      continue;
    }
  }
  return 0;
}
