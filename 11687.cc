#include <bits/stdc++.h>
using namespace std;

int r(int x) {
  // printf("X[0] -> %d\n", x);
  int i = 1;
  while (1) {
    int next;
    if (x == 0)
      next = 1; 
    else
      next = (int)ceil(log10(x + 1));
    i++;
    // printf("X[%d] -> %d\n", i, next);
    if (x == next)
      return i;
    x = next;
  }
}

int rs(int x) {
  // printf("X[0] -> %d\n", x);
  int i = 0;
  while (1) {
    int next;
    if (x == 0)
      next = 1; 
    else
      next = (int)ceil(log10(x + 1));
    i++;
    // printf("X[%d] -> %d\n", i, next);
    if (x == next)
      return i;
    x = next;
  }
}

int main() {
  char buff[1000001];
  while (1) {
    scanf("%s", &buff[0]);
    string S = buff;
    // printf("For case: %s\n", S.c_str());
    if (S == "END")
      break;
    if (S.size() == 1) // 1 digit
      printf("%d\n", rs(S[0] - '0'));
    else {
      int s = S.length();
      printf("%d\n", r(s));
    }
  }
  return 0;
}

// X0 = 2
// X1 = 1
// X2 = 1
