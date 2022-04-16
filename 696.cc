#include <bits/stdc++.h>
using namespace std;

int main() {

  int M, N;
  while (scanf("%d %d", &M, &N) != EOF) {
    if (M == 0 && N == 0)
      break;
    int ans;
    if (M == 0 || N == 0)
      ans = 0;
    else if (M >=4 && N >= 4)
      ans = max(4, (M*N + 1)/2);
    else if (M == 1)
      ans = N;
    else if (N == 1)
      ans = M;
    else if (M == 2) {
      if (N % 4 == 0)
        ans = N;
      else if (N % 4 == 1)
        ans = N + 1;
      else if (N % 4 == 2)
        ans = N + 2;
      else if (N % 4 == 3)
        ans = N + 1;
    } else if (N == 2) {
      if (M % 4 == 0)
        ans = M;
      else if (M % 4 == 1)
        ans = M + 1;
      else if (M % 4 == 2)
        ans = M + 2;
      else if (M % 4 == 3)
        ans = M + 1;
    } else if (M == 3 || N == 3) {
      ans = (N*M + 1)/2;
    }
    printf("%d knights may be placed on a %d row %d column board.\n", ans, M, N);
  }
  return 0;
}
