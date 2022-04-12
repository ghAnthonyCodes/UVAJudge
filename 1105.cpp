#include <bits/stdc++.h>
using namespace std;

#define vi_t  std::vector<int>
#define vvi_t std::vector<vi_t>

class FenwickTree2D {
 public:
  int M, N;
  vvi_t T;

  FenwickTree2D(int M, int N) { 
    this->M = M;
    this->N = N;
    T = vvi_t(M+1, vi_t(N + 1, 0));
  }

  void update(int x, int y, int val) {
    for (int i = x; i <= this->M; i = i | (i + 1)) {
      for (int j = y; j <= this->N; j = j | (j + 1))
        T[i][j] += val;
    }
  }

  int query(int x, int y) {
    int ret = 0;
    for (int xp = x; xp >= 0; xp = (xp & (xp + 1)) - 1) {
      for (int yp = y; yp >= 0; yp = (yp & (yp + 1)) - 1)
        ret += T[xp][yp];
    }
    return ret;
  }

  int queryRange(int x0, int y0, int x1, int y1) {
    return query(x1, y1) - query(x0 - 1, y1) - query(x1, y0 - 1) + query(x0 - 1, y0 - 1);
  }

  void clear(void) {
    T = vvi_t(M + 1, vi_t(N + 1, 0));
  }
};

class PS {
 public:
  int M, N;
  vvi_t T;
  PS(int M, int N) {
    this->M = M;
    this->N = N;
    T = vvi_t(M+1, vi_t(N+1, 0));
  }
  int queryRange(int x0, int y0, int x1, int y1) {
    if (x0 == 0 && y0 == 0)
      return T[x1][y1];
    if (x0 == 0)
      return T[x1][y1] - T[x1][y0-1];
    if (y0 == 0)
      return T[x1][y1] - T[x0-1][y1];
    return T[x1][y1] - T[x1][y0-1] - T[x0-1][y1] + T[x0-1][y0-1]; 
  }

  void buildPS(void) {
    for (int x=1; x<=M; x++) {
      for (int y=1; y<=M; y++)
        T[x][y] += T[x-1][y] + T[x][y-1] - T[x-1][y-1];
    }
  }
};

pair<int, int> rotate(double x, double y, int shift) {
  // printf("Rotating (%d %d)\n", (int)x, (int)y);
  double ang = atan(y/x);
  // printf("Origin Angle: %lf\n", ang*180.0/M_PI);
  double adjAng = ang + M_PI/4.0;
  // printf("Adjusted Angle: %lf\n", adjAng*180.0/M_PI);
  double len = sqrt(x*x + y*y);
  // printf("Origin Len: %lf\n", len);
  double adjLen = sqrt(2)*len;
  // printf("Adjusted Len: %lf\n", adjLen);
  int xp = adjLen*cos(adjAng) + shift + 0.5;
  int yp = adjLen*sin(adjAng) + 0.5;
  pair<int, int> pp = { xp, yp };
  // RMAP[pp] = { (int)x, (int)y };
  return pp;
}

pair<int, int> reverseRotate(double x, double y, int shift) {
  x -= shift;
  // printf("  Reverse Rotating (%d %d)\n", (int)x, (int)y);
  double ang = atan(y/x);
  if (ang < 0)
    ang = M_PI + ang;
  // printf("  Origin Angle: %lf\n", ang*180.0/M_PI);
  double adjAng = ang - M_PI/4.0;
  // printf("  Adjusted Angle: %lf\n", adjAng*180.0/M_PI);
  double len = sqrt(x*x + y*y);
  // printf("  Len: %lf\n", len);
  double adjLen = 1.0/sqrt(2.0)*len;
  // printf("  Adjusted Len: %lf\n", adjLen);
  return { adjLen*cos(adjAng) + 0.5, adjLen*sin(adjAng) + 0.5 };
}

int main() {
  int dx, dy, N, Q, m;
  double x, y;
  int tc = 1;

  while (scanf("%d %d %d %d", &dx, &dy, &N, &Q) != EOF) {
    if (dx == 0 && dy == 0 && N == 0 && Q == 0)
      break;
    // printf("Grid size: %d %d, rotated size: %d %d\n", dx, dy, 2*max(dx, dy), 2*max(dx, dy));
    printf("Case %d:\n", tc++);

    int gridSize = 2*max(dx, dy);
    // FenwickTree2D F = FenwickTree2D(gridSize+1, gridSize+1);
    PS ps = PS(gridSize+1, gridSize+1);
    for (int n=0; n<N; n++) {
      scanf("%lf %lf", &x, &y);
      pair<int, int> xyp = rotate(x, y, max(dx, dy));
      // F.update(xyp.first, xyp.second, 1);
      ps.T[xyp.first][xyp.second] = 1;
      // printf("(%lf %lf) -> (%d, %d)\n", x, y, xpyp.first, xpyp.second);
    }
    ps.buildPS();

    for (int q=0; q<Q; q++) {
      scanf("%d", &m);
      pair<int, int> mpt;
      int ans = 0;
      int xp;
      int yp;
      int gl = max(dx, dy);
      bool oddS = (gl & 1) == 1;
      for (int yp = 1; yp <= gridSize; yp += 1) {
        if (oddS == true) { 
          if ((yp & 1) == 0)
            xp = 1;
          else
            xp = 0;
        } else {
          if ((yp & 1) == 0)
            xp = 0;
          else
            xp = 1;
        }
        for (; xp <= gridSize+1; xp += 2) {
          int xp0 = max(0, xp-m);
          int yp0 = max(0, yp-m);
          int xp1 = min(xp+m, gridSize);
          int yp1 = min(yp+m, gridSize);
          // int a = F.queryRange(xp0, yp0, xp1, yp1);
          int a = ps.queryRange(xp0, yp0, xp1, yp1);
          // printf("Query[(%d %d), (%d %d), m=%d] = %d\n", xp0, yp0, xp1, yp1, m, a);
          // printf("%d vs. %d\n", a, b);
          if (a > ans) {
            mpt = reverseRotate(xp, yp, gl);
            if (mpt.first <= 0 || mpt.second <= 0)
              continue;
            ans = a;
            // printf("New A: %d @ %d %d\n", ans, mpt.first, mpt.second);
          } else if (a == ans) {
            pair<int, int> cmpt = reverseRotate(xp, yp, gl);
            if (cmpt.first <= 0 || cmpt.second <= 0)
              continue;
            if (cmpt.second < mpt.second || (cmpt.second == mpt.second && cmpt.first < mpt.first))
              mpt = cmpt;
          }

          // printf("Query(%d %d, %d %d): %d\n", xp-m, yp-m, xp+m, yp+m, a);
        }
      }
      // printf("%d (%d,%d)\n", ans, mx, my);
      if (ans == 0)
        printf("0 (1,1)\n");
      else {
        printf("%d (%d,%d)\n", ans, mpt.first, mpt.second);
      }
    }
  }
  return 0;
}
