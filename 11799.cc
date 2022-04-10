#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, N, s;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    int m = 0;
    for (int n=0; n<N; n++) {
      scanf("%d", &s); 
      m = max(s, m);
    }
    printf("Case %d: %d\n", tc, m);

  }
  return 0;
}
