#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  while (scanf("%d", &N) != EOF) {
    if (N == 0)
      break;
    int sheets = (int)ceil(N/4.0);
    int maxP = sheets*4;
    printf("Printing order for %d pages:\n", N);
    for (int sheet=0; sheet<sheets; sheet++) {
      printf("Sheet %d, front: ", sheet+1);
      if (maxP - sheet*2 > N)
        printf("Blank, ");
      else
        printf("%d, ", maxP - sheet*2);
      if (sheet*2+1 > N)
        printf("Blank\n");
      else
        printf("%d\n", sheet*2+1);

      if (sheet*2+2 > N && maxP - sheet*2 -1 > N)
        continue;
      printf("Sheet %d, back : ", sheet+1);
      if (sheet*2+2 > N)
        printf("Blank, ");
      else
        printf("%d, ", sheet*2+2);
      if (maxP - sheet*2 - 1 > N)
        printf("Blank\n");
      else
        printf("%d\n", maxP - sheet*2 - 1);
    }
  }
  return 0;
}
