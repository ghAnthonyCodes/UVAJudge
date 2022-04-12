#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, C, xi;
  while (scanf("%d %d", &A, &C) != EOF) {
    if (A == 0)
      return 0;
    int cDepth = A;
    int cuts = 0;
    for (int c=0; c<C; c++) {
      scanf("%d", &xi);
      if (xi < cDepth)
        cuts += (cDepth - xi);
      cDepth = xi;
    }
    printf("%d\n", cuts);
  }
  return 0;
}
