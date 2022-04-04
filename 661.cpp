#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
   int n, m, c;
   int seq = 1;
   while (scanf("%d %d %d", &n, &m, &c) != EOF) {
      if (n == 0 && m == 0 && c == 0)
         break;
      std::vector<int> D = std::vector<int>(n, 0);
      std::vector<bool> B = std::vector<bool>(n, false);
      int power;
      for (int i=0; i<n; i++) {
         scanf("%d", &power);
         D[i] = power;
      }
      int maxPower = 0;
      int curPower = 0;
      for (int i=0; i<m; i++) {
         int action;
         scanf("%d", &action);
         action -= 1;
         if (B[action] == false) {
            B[action] = true;
            curPower += D[action];
         } else {
            B[action] = false;
            curPower -= D[action];
         }
         maxPower = std::max(maxPower, curPower);
      }
      printf("Sequence %d\n", seq);
      if (maxPower > c) {
         printf("Fuse was blown.\n\n");
      } else {
         printf("Fuse was not blown.\n");
         printf("Maximal power consumption was %d amperes.\n\n", maxPower);
      }
      seq++;
   }
   return 0;
}
