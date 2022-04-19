#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, M;
  int input;
  while (scanf("%d %d", &N, &M) != EOF) {
    unordered_set<int> jack;
    unordered_set<int> jill;
    if (N == 0 && M == 0)
      break;
    for (int n=0; n<N; n++) {
      scanf("%d", &input);
      jack.insert(input);
    }
    for (int m=0; m<M; m++) {
      scanf("%d", &input);
      if (jack.find(input) != jack.end())
        jill.insert(input);
    }
    printf("%d\n", (int)jill.size());
  }
  return 0;
}
