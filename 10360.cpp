#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class FenwickTree2D {
 public:
  int M, N;
  vvi T;

  FenwickTree2D(int M, int N) { 
    this->M = M;
    this->N = N;
    this->T = vvi(M+1, vi(N + 1, 0));
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
    T = vvi(M + 1, vi(N + 1, 0));
  }
};

int main() {
   int T, D, N, x, y, rats;
   scanf("%d", &T);
   while (T--) {
      scanf("%d", &D);
      scanf("%d", &N);
      FenwickTree2D F = FenwickTree2D(1028, 1028);
      int maxCoord = 0;
      for (int n=0; n<N; n++) {
         scanf("%d %d %d", &x, &y, &rats);
         maxCoord = std::max(maxCoord, std::max(y, x));
         F.update(x, y, rats);
      }

      // Query based on bomb size
      int maxRats = 0;
      int px = 0;
      int py = 0;
      for (int x = 0; x <= maxCoord; x++) {
         for (int y = 0; y <= maxCoord; y++) {
            int q = F.queryRange(std::max(0, x-D), std::max(0, y-D), std::min(x+D, 1025), std::min(y+D, 1025));
            if (q > maxRats) {
               maxRats = q;
               px = x;
               py = y;
            }
         }
      }
      printf("%d %d %d\n", px, py, maxRats);
   }
   return 0;
}
