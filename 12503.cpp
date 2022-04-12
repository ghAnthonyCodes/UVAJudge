#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, N, i;
  char b[10];
  char c[10];
  string s;
  scanf("%d", &T);
  while (T--) {
    vector<int> I = { 0 };
    scanf("%d", &N);
    int xpos = 0;
    while (N--) {
      scanf("%s", b);
      s = b;
      int prev = 0;
      if (s == "LEFT") {
        xpos--;
        I.push_back(-1);
      } else if (s == "RIGHT") {
        xpos++;
        I.push_back(1);
      } else {
        scanf("%s %d", c, &i);
        xpos += I[i];
        I.push_back(I[i]);
      }
    }
    printf("%d\n", xpos);
  }
  return 0;
}
