#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  char Uc[10010];
  string U;
  scanf("%d", &T);
  while (T--) {
    int mPeak = 0;
    scanf("%s", Uc);
    U = Uc;

    int dist = 0;
    stack<int> Ds;
    int water = 0;
    for (int i=0; i<U.length(); i++) {
      if (U[i] == '\\') {
        Ds.push(i);
      } else if (U[i] == '/') {
        if (!Ds.empty()) {
          water += (i - Ds.top());
          Ds.pop();
        }
      }
    }
    printf("%d\n", water);
  }
  return 0;
}
