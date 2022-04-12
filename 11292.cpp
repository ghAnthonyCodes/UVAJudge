#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

int main() {
  int N, M;
  while (scanf("%d %d", &N, &M)) {
    if (N == 0 && M == 0)
      return 0;
    std::vector<int> dragonHeads = std::vector<int>(N);
    std::vector<int> knights = std::vector<int>(M);
    for (int n=0; n<N; n++)
      scanf("%d", &dragonHeads[n]);
    for (int m=0; m<M; m++)
      scanf("%d", &knights[m]);

    std::sort(dragonHeads.begin(), dragonHeads.end());
    std::sort(knights.begin(), knights.end());
    
    // Solve
    // For each knight, slay the largest dragon head it can
    int kp = 0;
    int cost = 0;
    bool doomed = false;
    for (auto& d : dragonHeads) {
      if (kp == M) {
        doomed = true;
        break;
      }
      while (knights[kp] < d) {
        kp++;
        if (kp == M) {
          doomed = true;
          break;
        }
      }
      if (doomed)
        break;
      else {
        // *slay dragon
        cost += knights[kp];
        kp++;
      }
    }

    if (doomed)
      printf("Loowater is doomed!\n");
    else
      printf("%d\n", cost);
  }
}
