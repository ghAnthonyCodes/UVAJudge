#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  double l, wi, d, we;
  int a = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf %lf %lf %lf", &l, &wi, &d, &we);
    if ((l <= 56 && wi <= 45 && d <= 25 && we <= 7) || ((l + wi + d) <= 125 && we <= 7)) {
      printf("1\n");
      a++;
    }
    else
      printf("0\n");
  }
  printf("%d\n", a);
  return 0;
}
