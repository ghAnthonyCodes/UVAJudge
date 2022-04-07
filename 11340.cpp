#include <iostream>
#include <cstdio>
using namespace std;

int main() {
   std::string S;
   int N, K, M;
   double V;
   char C;
   scanf("%d\n", &N);
   for (int n=0; n<N; n++) {
      double D[512] = { 0.0 };
      scanf("%d\n", &K);
      for (int k=0; k<K; k++) {
         scanf("%c %lf\n", &C, &V);
         D[C+128] = V;
      }
      scanf("%d\n", &M);
      double total = 0.0;
      for (int m=0; m<M; m++) {
         getline(cin, S);
         int ptr = 0;
         for (int i=0; i<S.length(); i++) {
            total += D[S[i]+128];
         }
      }
      printf("%0.2f$\n", total/100.0);
   }
   return 0;
}
