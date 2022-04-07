#include <cstdio>

int main() {
   int K, N, M, x, y;
   while (scanf("%d\n", &K) != EOF) {
      scanf("%d %d\n", &N, &M);

      for (int k=0; k<K; k++) {
         scanf("%d %d\n", &x, &y);
         if (x == N || y == M)
            printf("divisa\n");
         else if (x > N) {
            if (y > M)
               printf("NE\n");
            else
               printf("SE\n");
         } else {
            if (y > M)
               printf("NO\n");
            else
               printf("SO\n");
         }
      }
   }
   return 0;
}
