#include <bits/stdc++.h>
using namespace std;

double angle(int h, int m) {
  // How far around is the hour hand
  double hang, mang;
  if (h == 12)
    hang = 0.00;
  else
    hang = 360.0*h/12.0;
  mang = 360.0*m/60.0;
  hang += mang/360.0*30.0;
  // printf("(%.2lf, %.2lf)\n", hang, mang);
  double a = min(abs(hang-mang), abs(mang-hang));
  a = min(a, min(a, min(abs(360+hang - mang), abs(360+mang - hang))));
  return a;
}

int main() {
  char time[10];
  string T;
  int m, h;
  while (scanf("%s", time) != EOF) {
    T = time;
    if (T == "0:00")
      return 0;
    sscanf(time, "%d:%d", &h, &m);

    // Solve
    printf("%.3lf\n", angle(h, m));
  }
  return 0;
}
