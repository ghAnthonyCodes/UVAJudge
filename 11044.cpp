#include <cstdio>
#include <cmath>

int main() {

  int T, N, M;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &M);
    int xDir = std::ceil((N - 2.0)/3.0);
    int yDir = std::ceil((M - 2.0)/3.0);
    int ans = xDir * yDir;
    printf("%d\n", ans);
  }
  return 0;
}
