#include <cstdio>
#include <algorithm>
#include <vector>
int N;

int main() {
   int A, B, C;
   scanf("%d", &N);
   for (int n=1; n<=N; n++) {
      scanf("%d %d %d", &A, &B, &C);
      std::vector<int> V = { A, B, C };
      std::sort(V.begin(), V.end());
      printf("Case %d: %d\n", n, V[1]);

   }
   return 0;
}
