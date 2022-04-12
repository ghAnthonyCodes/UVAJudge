#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, B, H, W, p, w;
  while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF) {

    int ans = B + 1;
    for (int h=0; h<H; h++) {
      scanf("%d", &p);
      for (int wi=0; wi<W; wi++) {
        scanf("%d", &w);
        if (w >= N)
          ans = min(ans, N*p);
      }
    }
    if (ans == B + 1)
      printf("stay home\n");
    else
      printf("%d\n", ans);
  }

  // Solve
  return 0;
}
