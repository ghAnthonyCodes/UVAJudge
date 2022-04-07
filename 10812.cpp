#include <cstdio>

int main() {
  int N, s, d;
  scanf("%d", &N);
  while (N--) {
    scanf("%d %d", &s, &d);
    if (((d + s) & 1) == 1) {
      printf("impossible\n");
      continue;
    }
    // eq 1. a + b = s
    // eq 2. | a - b | = d
    //    2.1: a - b = d
    //    2.2: b - a = d


    // Possibility 1 (a won)
    // b = s - a
    // a - (s - a) = d
    // 2a - s = d, a = (d + s)/2, b = s - a
    int a = (d + s)/2;
    int b = s - a;
    if (a >= 0 && b >= 0) {
      printf("%d %d\n", a, b);
      continue;
    }

    // Possibility 2 (b won)
    // a = s - b
    // b - (s - b) = d
    // b = (d + s)/2
    b = (d + s)/2;
    a = s - b;
    if (a >= 0 && b >= 0) {
      printf("%d %d\n", a, b);
      continue;
    }

    printf("impossible\n");
  }
  return 0;
}
