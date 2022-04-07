#include <cstdio>
#include <cmath>

int main() {
   int T, N;
   scanf("%d", &T);
   while (T--) {
      scanf("%d", &N);
      int A = ((N*63 + 7492)*235)/47 - 498;
      printf("%d\n", abs(A/10 % 10));
   }
   return 0;
}
