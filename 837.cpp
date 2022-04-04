#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int T, N;
  scanf("%d", &T);
  for (int test=0; test<T; test++) {
    scanf("%d", &N);
    std::vector<std::pair<float, float>> V;
    for (int n=0; n<N; n++) {
      float x1, y1, x2, y2, f;
      scanf("%f %f %f %f %f", &x1, &y1, &x2, &y2, &f);
      if (x1 > x2) {
        if (f == 0.0f)
          f = 100;
        V.push_back({ x1, -f });
        V.push_back({ x2, f });
      } else {
        V.push_back({ x1, f });
        V.push_back({ x2, -f });
      }
    }

    std::sort(V.begin(), V.end());
    float prod = 1.0;

    printf("%d\n", (int)V.size() + 1);
    printf("-inf %.3f 1.000\n", V[0].first);
    int zeros = 0;
    for (int i = 0; i < V.size() - 1; i++) {
      if (V[i].second == 100)
        zeros++;
      else if (V[i].second == -100)
        zeros--;
      else if (V[i].second > 0)
        prod *= V[i].second;
      else
        prod /= -V[i].second;
      if (zeros > 0)
        printf("%.3f %.3f %.3f\n", V[i].first, V[i+1].first, 0.0f);
      else
        printf("%.3f %.3f %.3f\n", V[i].first, V[i+1].first, prod);
    }
    printf("%.3f +inf 1.000\n", V[V.size()-1].first);
    if (test != T-1)
      printf("\n");
  }


  return 0;
}
