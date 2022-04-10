#include <cstdio>
#include <cmath>

int main() {
   int T;
   double N;
   scanf("%d", &T);
   while (T--) {
      scanf("%lf", &N);
      double root1 = (-1.0 + std::sqrt(1.0 + 8.0*N))/2.0;
      printf("%llu\n", (long long)std::floor(root1));
   }
   return 0;
}
