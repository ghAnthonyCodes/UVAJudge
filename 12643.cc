#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll nextN, N, i, j;
  while (scanf("%lld %lld %lld", &N, &i, &j) != EOF) {
    if (j < i)
      swap(i, j);
    int round = 1;
    while (true) {
      if ((i & 1) == 1 && (j <= (i + 1))) {
        printf("%d\n", round);
        break;
      }

      i = (i+1)/2;
      j = (j+1)/2;
      round++;
    }
  }
  return 0;
}
