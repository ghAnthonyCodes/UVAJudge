#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main() {
  int B, V, bytes, Q;
  char name[21];
  string nameS;
  while (scanf("%d %d", &B, &V) != EOF) {
    map<string, ull> M;
    vector<pair<string, int>> byteM;
    for (int v=0; v<V; v++) {
      scanf("%s %d", name, &bytes);
      nameS = name;
      byteM.push_back({ nameS, bytes });
    }
    for (auto& p : byteM) {
      ull g = 0;
      for (int x=0; x<p.second; x++) {
        scanf("%s", name);
        nameS = name;
        int y = stoul(nameS, nullptr, 2);
        g = (g << B) | y;
      }
      M[p.first] = g;
    }
    scanf("%d", &Q);
    for (int q=0; q<Q; q++) {
      scanf("%s", name);
      nameS = name;
      printf("%s=", nameS.c_str());
      if (M.find(nameS) == M.end())
        printf("\n");
      else
        printf("%llu\n", M[nameS]);
    }
  }
  return 0;
}
