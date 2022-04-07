#include <cstdio>
#include <algorithm>

int main() {
  int N;
  while (scanf("%d", &N) != EOF) {

    // Try + N
    int maxBottles = -1;
    for (int addition=0; addition<3; addition++) {

      int fullBottles = N;
      int emptyBottles = addition;
      int drank = 0;

      while (true) {
        // 1. drink your full bottles
        drank += fullBottles;
        emptyBottles += fullBottles;
        fullBottles = 0;

        // 2. Get new bottles
        fullBottles = emptyBottles/3;
        emptyBottles = emptyBottles % 3;

        if (fullBottles == 0) {
          break;
        }
      }
      if (emptyBottles >= addition)
        maxBottles = std::max(drank, maxBottles);
    }
    printf("%d\n", maxBottles);

  }
  return 0;
}
