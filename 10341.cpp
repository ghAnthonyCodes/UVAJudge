#include <cstdio>
#include <cmath>
#include <limits>

// p*e^-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x^2 = -u
double f(double x, double p, double q, double r, double s, double t, double u) {
   return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {
   double p, q, r, s, t, u;
   while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) != EOF) {

      // Start point
      double a = f(0.0, p, q, r, s, t, u);
      double b = f(1.0, p, q, r, s, t, u);
      if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
         printf("No solution\n");
         continue;
      }

      double left = 0, right = 1.0;
      double m;
      for (int i=0; i<1000; i++) {
         // printf("M: %lf\n", m);
         m = left + (right - left)/2.0;
         if (f(m, p, q, r, s, t, u) < 0)
            right = m;
         else
            left = m;
      }
      printf("%.4lf\n", m);
   }
   return 0;
}
