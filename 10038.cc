#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x, prev;
  while (scanf("%d", &N) != EOF) {
    vector<bool> found = vector<bool>(N, false);
    scanf("%d", &prev);
    for (int n=1; n<N; n++) {
      scanf("%d", &x);
      found[abs(x - prev)] = true;
      prev = x;
    }

    bool jolly = true;
    for (int i=1; i<N; i++)
      jolly &= found[i];
      
    printf("%s\n", jolly ? "Jolly" : "Not jolly");
  }
  return 0;
}
