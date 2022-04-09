#include <cstdio>
#include <vector>
#include <algorithm>

#define vi std::vector<int>
#define vvi std::vector<vi>

int main() {
   int T, M, C, K, e;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &M, &C);
      vvi A = vvi(C);
      for (int c=0; c<C; c++) {
         scanf("%d", &K);
         A[c] = vi(K, 0);
         for (int k=0; k<K; k++)
            scanf("%d", &A[c][k]);
      }

      // Solve
      vvi D = vvi(M + 1, vi(C + 1, 0));
      for (int cat = 1; cat <= C; cat++) {
         for (int m = 1; m <= M; m++) {
            int d = D[m][cat - 1];
            for (auto& a : A[cat - 1]) {
               if ((m - a) >= 0) {
                  int v = a + D[m - a][cat - 1];
                  if (v <= m)
                     d = std::max(d, v);
               }
            }
            D[m][cat] = d;
         }
      }

      int minCost = 0;
      for (auto& cat : A)
         minCost += *std::min_element(std::begin(cat), std::end(cat));
      if (minCost > M)
         printf("no solution\n");
      else
         printf("%d\n", D[M][C]);
   }
   return 0;
}
