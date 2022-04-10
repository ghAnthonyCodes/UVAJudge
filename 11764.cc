#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, N, W, nW;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    scanf("%d", &W);
    int l = 0; 
    int h = 0;
    for (int n=1; n<N; n++) {
      scanf("%d", &nW);
      if (nW > W)
        h++;
      else if (nW < W)
        l++;
      W = nW;
    }
    printf("Case %d: %d %d\n", tc, h, l);
  }
  return 0;
}
