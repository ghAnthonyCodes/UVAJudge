#include <bits/stdc++.h>
using namespace std;

int r(int N) {
  while (1) {
    int sum = 0;
    if (N < 10)
      return N;
    while (N >= 1) {
      sum += N % 10;
      N /= 10;
    }
    N = sum;
  }
}

int main() {

  int N;
  while (scanf("%d", &N) != EOF) {
    if (N == 0)
      break;
    printf("%d\n", r(N));
  }
  return 0;
}
