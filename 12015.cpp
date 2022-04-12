#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  char site[120];
  int rank;
  string S;
  scanf("%d", &T);
  for (int tc=1; tc<=T; tc++) {
    vector<string> m;
    int mi = 0;
    for (int i=0; i<10; i++) {
      scanf("%s %d", site, &rank);
      S = site;
      if (rank == mi) {
        m.push_back(S);
      } else if (rank > mi) {
        mi = rank;
        m = { S };
      }
    }
    printf("Case #%d:\n", tc);
    for (auto mm : m) {
      printf("%s\n", mm.c_str());
    }

  }
  return 0;
}
