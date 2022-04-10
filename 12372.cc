#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, L, W, H;
  scanf("%d", &T);

  for (int tc = 1; tc <= T; tc++) {
    scanf("%d %d %d", &L, &W, &H);
    if (L <= 20 && W <= 20 && H <= 20) 
      printf("Case %d: good\n", tc);
    else
      printf("Case %d: bad\n", tc);
  }
  return 0;
}
