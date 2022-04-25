#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, a, f;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d %d", &a, &f);

    for (int x=0; x<f; x++) {
      // Print up
      for (int i=1; i<=a; i++) {
        for (int j=0; j<i; j++)
          printf("%d", i);
        printf("\n");
      }
      // Print down
      for (int i=a-1; i>0; i--) {
        for (int j=0; j<i; j++)
          printf("%d", i);
        printf("\n");
      }
      // Don't print last
      if (x < f-1)
        printf("\n");
    }
    if (tc <= T-1)
      printf("\n");
  }
  return 0;
}
