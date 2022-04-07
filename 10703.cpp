#include <cstdio>
#include <map>
#include <utility>

int main() {
  int W, H, N, a, b, c, d;
  while (scanf("%d %d %d", &W, &H, &N) != EOF) {
    if (W == 0 && H == 0 && N == 0)
      return 0;

    int u[500][500] = { 0 };
    int l[500][500] = { 0 };
    
    for (int n=0; n<N; n++) {
      scanf("%d %d %d %d", &a, &b, &c, &d);
      int blX = std::min(a, c)-1;
      int blY = std::min(b, d)-1;
      int trX = std::max(a, c)-1;
      int trY = std::max(b, d)-1;
      for (int row=blY; row <= trY; row++) {
        u[blX][row] += 1;
        l[trX][row] -= 1;
      }

    }

    int in = 0;
    int tot = 0;
    for (int r=0; r<H; r++) {
      for (int c=0; c<W; c++) {
        in += u[c][r];
        if (in == 0) {
          tot++;
        }
        in += l[c][r];
      }
    }
    if (tot == 0)
      printf("There is no empty spots.\n");
    else if (tot == 1)
      printf("There is one empty spot.\n");
    else
      printf("There are %d empty spots.\n", tot);
  }
  return 0;
}
