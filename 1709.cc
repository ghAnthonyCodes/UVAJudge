#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  double p, a, b, c, d;
  while (scanf("%lf %lf %lf %lf %lf %d", &p, &a, &b, &c, &d, &n) != EOF) {
    
    double mx = -10e9;
    double an = 0.0;
    for (int i=1; i<=n; i++) {
      double nx = p*(sin(a*i + b) + cos(c*i + d) + 2.0);
      mx = max(mx, nx);
      an = max(an, mx - nx);
    }
    printf("%lf\n", an);
  }
  return 0;
}
