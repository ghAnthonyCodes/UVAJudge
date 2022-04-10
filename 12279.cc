#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, x, tc = 1;
  while (scanf("%d", &N) != EOF) {
    if (N == 0)
      return 0;
    int b = 0;
    for (int n=0; n<N; n++) {
      scanf("%d", &x);
      b = (x > 0) ? b + 1 : b - 1;
    }
    printf("Case %d: %d\n", tc++, b);
  }
  return 0;
}
