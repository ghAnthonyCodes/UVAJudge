#include <bits/stdc++.h>
using namespace std;

int main() {
  int B, N, D, C, V;
  while (scanf("%d %d", &B, &N) != EOF) {
    if (B == 0 && N == 0)
      break;
    vector<int> reserves = vector<int>(B);
    for (int b=0; b<B; b++)
      scanf("%d", &reserves[b]); 

    // Read in 
    for (int n=0; n<N; n++) {
      scanf("%d %d %d", &D, &C, &V); 
      reserves[D-1] -= V;
      reserves[C-1] += V;
    }

    if (*min_element(reserves.begin(), reserves.end()) < 0)
      printf("N\n");
    else
      printf("S\n");
  }
  return 0;
}
