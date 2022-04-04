#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#define ull unsigned long long

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char C[21];
    ull N;
    std::vector<char> V; 
    while (scanf("%s %lld", &C[0], &N) != EOF) {
      std::string S = C; 
      for (auto& s : S)
        V.push_back(s);
      std::sort(V.begin(), V.end());

      ull n = 0;

      for (int digit = 0; digit < S.length(); digit++) {
        ull fact = 1;
        for (ull f = 2; f < S.length() - digit; f++) {
          fact *= f;
        }
        for (int i=0; i<V.size(); i++) {
          if (n + fact > N) {
            printf("%c", V[i]);
            V.erase(V.begin() + i);
            break;
          } else {
            n += fact;
          }
        }
      }
      printf("\n");
    }
  }
  return 0;
}
