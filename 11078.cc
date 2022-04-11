#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, N, i;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    int maxSenior = -1000000000;
    int maxDiff = -1000000000;
    for (int n=0; n<N; n++) {
      scanf("%d", &i);
      maxDiff = max(maxDiff, maxSenior - i); 
      maxSenior = max(maxSenior, i);
    }
    printf("%d\n", maxDiff);
  }
  return 0;
}
