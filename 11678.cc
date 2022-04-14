#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  int x;
  while (scanf("%d %d", &A, &B) != EOF) {
    if (A == 0 && B == 0)
      return 0;
    set<int> aU;
    set<int> bU;
    for (int a=0; a<A; a++) {
      scanf("%d", &x);
      aU.insert(x);
    }
    for (int b=0; b<B; b++) {
      scanf("%d", &x);
      bU.insert(x);
    }

    int aHasBDoesnt = 0;
    int bHasADoesnt = 0;
    for (auto& a : aU) {
      if (bU.find(a) == bU.end())
        aHasBDoesnt++;
    }

    for (auto& b : bU) {
      if (aU.find(b) == aU.end())
        bHasADoesnt++;
    }

    printf("%d\n", min(aHasBDoesnt, bHasADoesnt));
  }
  return 0;
}
